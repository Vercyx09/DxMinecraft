#include "BlockType.h"
#include "Chunk.h"
#include "DLog.h"
#include "FastNoiseLite.h"
#include "ThreadPool.h"
#include "Types.h"
#include "World.h"
#include <atomic>
#include <cmath>
#include <DMath.h>
#include <DxUtil.h>
#include <memory>
#include <unordered_set>
#include <vector>

World::World(int32 seed)
	:
	mPerlinNoise(seed)
{
	mPerlinNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

	mPerlinNoise.SetFractalType(FastNoiseLite::FractalType_FBm);
	mPerlinNoise.SetFractalOctaves(5);
	mPerlinNoise.SetFractalLacunarity(2.0f);
	mPerlinNoise.SetFractalGain(0.5f);
	mPerlinNoise.SetFrequency(0.0035f);

	mThreadPool = std::make_unique<ThreadPool>(1);
}

void World::Init(Vector3D playerPosition)
{
	mCurrentChunk = PositionToChunkCoordinates(playerPosition);
	GenerateChunks();
	mThreadPool->EnqueueTask(
		[this]()
		{
			mInitialized = true;
		}
	);
}

void World::Update(Vector3D playerPosition)
{
	ChunkCoordinates chunkCoordinates = PositionToChunkCoordinates(playerPosition);

	if (chunkCoordinates != mCurrentChunk)
	{
		DLog::Log("({}, {}) --> ({}, {})", mCurrentChunk.x, mCurrentChunk.y, chunkCoordinates.x, chunkCoordinates.y);
		mCurrentChunk = chunkCoordinates;
		UnloadChunks();
		GenerateChunks();
	}
}

void World::Shutdown()
{
	mThreadPool.reset();
	mChunks.Clear();
}

void World::GenerateChunk(ChunkCoordinates coordinates)
{
	mChunks.AddChunk(std::make_shared<Chunk>(*this, coordinates));
	mThreadPool->EnqueueTask(
		[coordinates, this]()
		{
			if (std::shared_ptr<Chunk> chunk = GetChunkWeak(coordinates).lock())
			{
				//DLog::Log("Generated chunk at: ({}, {})", coordinates.x, coordinates.y);
				chunk->SetBlockData(GenerateChunkBlockData(coordinates));
				chunk->BuildChunkMesh();
				chunk->SetIsRenderDataDirty(true);
				//MarkNeighboursDirty(coordinates);
			}
		}
	);
}

void World::UnloadChunk(ChunkCoordinates coordinates)
{
	DLog::Log("Unloading chunk at ({}, {})", coordinates.x, coordinates.y);
	DeleteChunk(coordinates);
	/*	if (Chunk* chunk = mChunks.GetChunk(coordinates))
		{

			chunk->MarkForDeletion();
		}*/
}

void World::GenerateChunks()
{
	const int32 maxDistance = static_cast<int32>(mRenderDistance) + 1;
	std::unordered_set<ChunkCoordinates> chunksToBuild;

	for (int32 distance = 0; distance <= maxDistance; ++distance)
	{
		for (int32 dx = -distance; dx <= distance; ++dx)
		{
			const int32 dzAbs = distance - std::abs(dx); // dist = |dx| + |dz| -> |dz| = dist - |dx|

			// For every dx generate the 2 mirrored dz
			for (int32 sign = -1; sign <= 1; sign += 2)
			{
				const int32 dz = dzAbs * sign;

				// Skip one iteration of the "center line" as there is no mirrored dz there
				if (dzAbs == 0 && sign == -1)
				{
					continue;
				}

				// Skip the 4 outer tips
				if (distance == maxDistance && (dx == 0 || dz == 0))
				{
					continue;
				}

				ChunkCoordinates coordinates{
					mCurrentChunk.x + dx,
					mCurrentChunk.y + dz
				};

				if (!mChunks.ContainsChunk(coordinates))
				{
					// The new chunk
					chunksToBuild.insert(coordinates);

					// The neighbours
					if (mChunks.ContainsChunk({ coordinates.x - 1, coordinates.y }))
					{
						chunksToBuild.insert({ coordinates.x - 1, coordinates.y });
					}
					if (mChunks.ContainsChunk({ coordinates.x + 1, coordinates.y }))
					{
						chunksToBuild.insert({ coordinates.x + 1, coordinates.y });
					}
					if (mChunks.ContainsChunk({ coordinates.x, coordinates.y - 1 }))
					{
						chunksToBuild.insert({ coordinates.x, coordinates.y - 1 });
					}
					if (mChunks.ContainsChunk({ coordinates.x, coordinates.y + 1 }))
					{
						chunksToBuild.insert({ coordinates.x, coordinates.y + 1 });
					}

					mChunks.AddChunk(std::make_shared<Chunk>(*this, coordinates));

					mThreadPool->EnqueueTask(
						[coordinates, this]()
						{
							if (std::shared_ptr<Chunk> chunk = GetChunkWeak(coordinates).lock())
							{
								//DLog::Log("Generated chunk at: ({}, {})", coordinates.x, coordinates.y);
								chunk->SetBlockData(GenerateChunkBlockData(coordinates));
								//chunk->BuildChunkMesh();
								//MarkNeighboursDirty(coordinates);
							}
						}
					);


					//GenerateChunk(chunkCoordinates);
				}
			}
		}

	}
	for (auto coordinates : chunksToBuild)
	{
		mThreadPool->EnqueueTask(
			[coordinates, this]()
			{
				if (std::shared_ptr<Chunk> chunk = GetChunkWeak(coordinates).lock())
				{
					//DLog::Log("Generated chunk at: ({}, {})", coordinates.x, coordinates.y);
					//chunk->SetBlockData(GenerateChunkBlockData(coordinates));
					chunk->BuildChunkMesh();
					//chunk->SetIsRenderDataDirty(true);
					//MarkNeighboursDirty(coordinates);
				}
			}
		);
	}
}

void World::UnloadChunks()
{
	const auto& chunks = mChunks.GetChunks();
	for (auto it = chunks.begin(); it != chunks.end();)
	{

		const ChunkCoordinates coordinates = (*it)->GetChunkCoordinates();
		const int32 maxDistance = mRenderDistance + 1;
		const int32 dx = coordinates.x - mCurrentChunk.x;
		const int32 dz = coordinates.y - mCurrentChunk.y;

		const int32 distance = std::abs(dx) + std::abs(dz);

		if (distance > maxDistance || (distance == maxDistance && (dx == 0 || dz == 0)))
		{
			it = mChunks.RemoveChunk(coordinates);

			//UnloadChunk(coords); // Marks for deletion
		}
		else
		{
			it++;
		}
	}


	/*	for (const auto& chunk : mChunks.GetChunks())
		{
			const ChunkCoordinates coords = chunk->GetChunkCoordinates();
			const int32 maxDistance = mRenderDistance + 1;
			const int32 dx = coords.x - mCurrentChunk.x;
			const int32 dz = coords.y - mCurrentChunk.y;

			const int32 distance = std::abs(dx) + std::abs(dz);

			if (distance > maxDistance || (distance == maxDistance && (dx == 0 || dz == 0)))
			{
				UnloadChunk(coords); // Marks for deletion
			}
		}*/
}

void World::DeleteChunk(ChunkCoordinates coordinates)
{
	mChunks.RemoveChunk(coordinates);
}

EBlockType World::GetBlockAt(Vector3D position)
{
	const Chunk* chunk = GetChunk(PositionToChunkCoordinates(position));
	ensure(chunk);

	return chunk->IsMeshBuilt() ? chunk->GetBlockAt(PositionToBlockCoordinates(position)) : EBlockType::Air;
}

EBlockType World::GenerateBlock(int32 x, int32 y, int32 z)
{
	int32 surface = static_cast<int32>(100.0f + mPerlinNoise.GetNoise(static_cast<float>(x), static_cast<float>(z)) * 20.0f);

	if (y < surface - 4)
	{
		return EBlockType::Stone;
	}
	if (y < surface - 1)
	{
		return EBlockType::Dirt;
	}
	if (y < surface)
	{
		return EBlockType::GrassBlock;
	}
	return EBlockType::Air;
}

std::vector<EBlockType> World::GenerateChunkBlockData(ChunkCoordinates coordinates)
{
	std::vector<EBlockType> blockData = std::vector<EBlockType>(CHUNK_VOLUME);

	for (uint32 y = 0; y < CHUNK_HEIGHT; ++y)
	{
		for (uint32 z = 0; z < CHUNK_SIZE; ++z)
		{
			for (uint32 x = 0; x < CHUNK_SIZE; ++x)
			{
				blockData[GetBlockIndex(x, y, z)] = GenerateBlock(x + coordinates.x * CHUNK_SIZE, y, z + coordinates.y * CHUNK_SIZE);
			}
		}
	}

	return blockData;
}

void World::MarkNeighboursDirty(ChunkCoordinates coordinates)
{
	if (Chunk* northChunk = GetChunk({ coordinates.x, coordinates.y - 1 }))
	{
		northChunk->SetIsMeshDirty(true);
	}
	if (Chunk* southChunk = GetChunk({ coordinates.x, coordinates.y + 1 }))
	{
		southChunk->SetIsMeshDirty(true);
	}
	if (Chunk* westChunk = GetChunk({ coordinates.x - 1, coordinates.y }))
	{
		westChunk->SetIsMeshDirty(true);
	}
	if (Chunk* eastChunk = GetChunk({ coordinates.x + 1, coordinates.y }))
	{
		eastChunk->SetIsMeshDirty(true);
	}
}