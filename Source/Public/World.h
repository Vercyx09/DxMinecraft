#pragma once
#include "BlockType.h"
#include "Chunk.h"
#include "Core.h"
#include "DxUtil.h"
#include "FastNoiseLite.h"
#include "ThreadPool.h"
#include "Types.h"
#include <atomic>
#include <cmath>
#include <memory>
#include <mutex>
#include <span>
#include <unordered_map>
#include <utility>
#include <vector>

class ChunkCollection
{
public:

	void AddChunk(std::shared_ptr<Chunk> chunk)
	{
		const ChunkCoordinates coords = chunk->GetChunkCoordinates();

		std::lock_guard lock{ mutex };
		ensure(!mMap.contains(coords));

		mChunks.emplace_back(std::move(chunk));
		mMap.insert({ coords, mChunks.size() - 1 });
	}

	//TODO: add emplace

	auto RemoveChunk(ChunkCoordinates coordinates)
	{
		std::lock_guard lock{ mutex };
		auto it = mMap.find(coordinates);
		ensure(it != mMap.end());

		std::size_t index = it->second;
		std::size_t backChunkIndex = mChunks.size() - 1;

		if (index != backChunkIndex)
		{
			ChunkCoordinates backChunkCoords = mChunks.back()->GetChunkCoordinates();

			std::swap(mChunks[index], mChunks.back());
			mMap[backChunkCoords] = index;
		}

		mChunks.pop_back();
		mMap.erase(it);

		// Return iterator to next valid element
		if (index < mChunks.size())
		{
			return mChunks.begin() + index;
		}
		else
		{
			return mChunks.end();
		}
	}

	void Clear()
	{
		std::lock_guard lock{ mutex };
		mChunks.clear();
		mMap.clear();
	}

	[[nodiscard]] bool ContainsChunk(ChunkCoordinates coordinates)
	{
		std::lock_guard lock{ mutex };
		return mMap.contains(coordinates);
	}

	[[nodiscard]] std::weak_ptr<Chunk> GetChunkWeak(ChunkCoordinates coordinates)
	{
		std::lock_guard lock{ mutex };
		auto it = mMap.find(coordinates);
		return it != mMap.end() ? mChunks[it->second] : nullptr;
	}

	[[nodiscard]] Chunk* GetChunk(ChunkCoordinates coordinates)
	{
		std::lock_guard lock{ mutex };
		auto it = mMap.find(coordinates);
		return it != mMap.end() ? mChunks[it->second].get() : nullptr;
	}

	[[nodiscard]] std::vector<std::shared_ptr<Chunk>>& GetChunks()
	{
		std::lock_guard lock{ mutex };
		return mChunks;
	}

protected:

	std::vector<std::shared_ptr<Chunk>> mChunks;
	std::unordered_map<ChunkCoordinates, std::size_t> mMap;
	std::mutex mutex;
};


[[nodiscard]] inline constexpr ChunkCoordinates PositionToChunkCoordinates(Vector3D position)
{
	return ChunkCoordinates{
		static_cast<int32>(std::floor(position.x / CHUNK_SIZE)),
		static_cast<int32>(std::floor(position.z / CHUNK_SIZE))
	};
}

[[nodiscard]] inline constexpr BlockCoordiantes PositionToBlockCoordinates(Vector3D position)
{
	return BlockCoordiantes{
		(static_cast<int32>(std::floor(position.x)) % 16 + 16) % 16,
		static_cast<int32>(std::floor(position.y)),
		(static_cast<int32>(std::floor(position.z)) % 16 + 16) % 16
	};
}


class World
{
public:

	World(int32 seed);

public:

	void Init(Vector3D playerPosition);

	void Update(Vector3D playerPosition);

	void Shutdown();

protected:

	void GenerateChunks();

	void UnloadChunks();

	void GenerateChunk(ChunkCoordinates coordinates);

	void UnloadChunk(ChunkCoordinates coordinates);

	void DeleteChunk(ChunkCoordinates coordinates);

public:

	//[[nodiscard]] FORCEINLINE std::span<const std::shared_ptr<Chunk>> GetChunks() const noexcept { return mChunks.GetChunks(); }

	[[nodiscard]] FORCEINLINE std::span<std::shared_ptr<Chunk>> GetChunks() noexcept { return mChunks.GetChunks(); }

	[[nodiscard]] FORCEINLINE std::weak_ptr<Chunk> GetChunkWeak(ChunkCoordinates coordinates)
	{
		return mChunks.GetChunkWeak(coordinates);
	}

	[[nodiscard]] FORCEINLINE Chunk* GetChunk(ChunkCoordinates coordinates)
	{
		return mChunks.GetChunk(coordinates);
	}

	[[nodiscard]] EBlockType GetBlockAt(Vector3D position);

	[[nodiscard]] FORCEINLINE bool IsInitialized() const noexcept { return mInitialized.load(); }

protected:

	[[nodiscard]] EBlockType GenerateBlock(int32 x, int32 y, int32 z);

	[[nodiscard]] std::vector<EBlockType> GenerateChunkBlockData(ChunkCoordinates coordinates);

	void MarkNeighboursDirty(ChunkCoordinates coordinates);

protected:

	ChunkCollection mChunks;

	uint32 mRenderDistance = 10;

	ChunkCoordinates mCurrentChunk = { 0, 0 };

	std::atomic<bool> mInitialized = false;

protected:

	FastNoiseLite mPerlinNoise;

	std::unique_ptr<ThreadPool> mThreadPool;
};