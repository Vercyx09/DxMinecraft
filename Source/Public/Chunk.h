#pragma once
#include "BlockTexture.h"
#include "BlockType.h"
#include "Core.h"
#include "DMath.h"
#include "Renderer.h"
#include "Types.h"
#include <atomic>
#include <DirectXMath.h>
#include <memory>
#include <utility>
#include <vector>

class World;
struct DirectX::XMFLOAT4X4;


struct TextureAtlasCoords
{
	uint32 x;
	uint32 y;
};



struct BlockVertex
{
	Vector3D position;
	Vector3D normal;
	uint16 textureOffset;
	uint16 overlayTextureOffset;

	Vector2D textureUV;
	Color textureTint = { 255, 255, 255, 255 };
	Color overlayTextureTint = { 255, 255, 255, 255 };
};

struct Face {
	Vector3D normal;
	Vector3D vertices[4];
	Vector2D uvs[4];
	EBlockFace face;
};


constexpr uint32 CHUNK_SIZE = 16;
constexpr uint32 CHUNK_HEIGHT = 256;
constexpr uint32 CHUNK_VOLUME = CHUNK_SIZE * CHUNK_SIZE * CHUNK_HEIGHT;

[[nodiscard]] inline constexpr std::size_t GetBlockIndex(uint32 x, uint32 y, uint32 z)
{
	return x + CHUNK_SIZE * (z + CHUNK_SIZE * static_cast<std::size_t>(y));
}

using BlockCoordiantes = DMath::TVector3D<int32>;
using ChunkCoordinates = DMath::TVector2D<int32>;

struct MeshData
{
	std::vector<BlockVertex> vertices;
	std::vector<uint32> indices;
};


class Chunk
{
public:

	Chunk(World& world, ChunkCoordinates chunkCoordinates);
	~Chunk() = default;

	Chunk(const Chunk&) = delete;
	Chunk& operator=(const Chunk&) = delete;
	Chunk(Chunk&&) = delete;
	Chunk& operator=(Chunk&&) = delete;

public:

	void BuildChunkMesh();

public:

	[[nodiscard]] FORCEINLINE const std::shared_ptr<const MeshData> GetMeshData() const { return std::atomic_load(&mMeshData); }

	[[nodiscard]] FORCEINLINE ChunkCoordinates GetChunkCoordinates() const noexcept { return mChunkCoordinates; }

	[[nodiscard]] FORCEINLINE RenderData* GetRenderData() const noexcept { return mRenderData.get(); }

	[[nodiscard]] FORCEINLINE const DirectX::XMFLOAT4X4& GetWorldMatrix() const noexcept { return mWorldMatrix; }

	[[nodiscard]] EBlockType GetBlockAt(BlockCoordiantes coordinates) const;

public:

	[[nodiscard]] FORCEINLINE bool IsMarkedForDeletion() const noexcept { return mMarkedForDeletion; }

	[[nodiscard]] FORCEINLINE bool IsMeshBuilt() const noexcept { return mMeshBuilt; }

	[[nodiscard]] FORCEINLINE bool IsMeshDirty() const noexcept { return mMeshDirty; }

	[[nodiscard]] FORCEINLINE bool IsRenderDataDirty() const noexcept { return mRenderDataDirty; }

public:

	void MarkForDeletion() noexcept { mMarkedForDeletion = true; }

	void SetIsMeshDirty(bool dirty) noexcept { mMeshDirty = dirty; }

	void SetIsRenderDataDirty(bool dirty) { mRenderDataDirty = dirty; }

	void SetIsMeshBuilt(bool built) noexcept { mMeshBuilt = built; }

public:

	void SetRenderData(std::unique_ptr<RenderData> renderData);


	[[nodiscard]] std::shared_ptr<const std::vector<EBlockType>> GetBlockData() const
	{
		return mBlockData;
	}

	void SetBlockData(std::vector<EBlockType>&& blockData)
	{
		mBlockData = std::make_shared<const std::vector<EBlockType>>(std::move(blockData));
	}

protected:

	void CreateRenderData();

protected:

	std::atomic<std::shared_ptr<const MeshData>> mMeshData;
	std::atomic<std::shared_ptr<const std::vector<EBlockType>>> mBlockData;
	ChunkCoordinates mChunkCoordinates;

protected:

	World& mWorld;
	bool mMarkedForDeletion = false;
	bool mMeshDirty = true;
	std::atomic<bool> mRenderDataDirty = false;
	std::atomic<bool> mBuildingMesh = false;
	bool mMeshBuilt = false;

protected:

	std::unique_ptr<RenderData> mRenderData;
	DirectX::XMFLOAT4X4 mWorldMatrix;

protected:

	inline static Face faces[6] = {
		// Top
		Face{
			.normal = { 0, 1, 0 },
			.vertices = {
			   { 0.0f, 1.0f, 0.0f },
			   { 0.0f, 1.0f, 1.0f },
			   { 1.0f, 1.0f, 1.0f },
			   { 1.0f, 1.0f, 0.0f }
			},
			.uvs = {
				{ 0, 1 },
				{ 0, 0 },
				{ 1, 0 },
				{ 1, 1 }
			},
			.face = EBlockFace::Top
		},
		// Bottom
		Face{
			.normal = { 0, -1, 0 },
			.vertices = {
				{ 0.0f, 0.0f, 1.0f },
				{ 0.0f, 0.0f, 0.0f },
				{ 1.0f, 0.0f, 0.0f },
				{ 1.0f, 0.0f, 1.0f }
			},
			.uvs = {
				{ 0, 1 },
				{ 0, 0 },
				{ 1, 0 },
				{ 1, 1 }
			},
			.face = EBlockFace::Bottom
		},
		// Front
		Face{
			.normal = { 0, 0, -1 },
			.vertices = {
				{ 0.0f, 0.0f, 0.0f },
				{ 0.0f, 1.0f, 0.0f },
				{ 1.0f, 1.0f, 0.0f },
				{ 1.0f, 0.0f, 0.0f }
			},
			.uvs = {
				{ 0, 1 },
				{ 0, 0 },
				{ 1, 0 },
				{ 1, 1 }
			},
			.face = EBlockFace::Front
		},
		// Back
		Face{
			.normal = { 0, 0, 1 },
			.vertices = {
				{ 0.0f, 0.0f, 1.0f },
				{ 1.0f, 0.0f, 1.0f },
				{ 1.0f, 1.0f, 1.0f },
				{ 0.0f, 1.0f, 1.0f }
			},
			.uvs = {
				{ 1, 1 },
				{ 0, 1 },
				{ 0, 0 },
				{ 1, 0 }
			},
			.face = EBlockFace::Side
		},
		// Left
		Face{
			.normal = { -1, 0, 0 },
			.vertices = {
				{ 0.0f, 0.0f, 1.0f },
				{ 0.0f, 1.0f, 1.0f },
				{ 0.0f, 1.0f, 0.0f },
				{ 0.0f, 0.0f, 0.0f }
			},
			.uvs = {
				{ 0, 1 },
				{ 0, 0 },
				{ 1, 0 },
				{ 1, 1 }
			},
			.face = EBlockFace::Side
		},
		// Right
		Face{
			.normal = { 1, 0, 0 },
			.vertices = {
				{ 1.0f, 0.0f, 0.0f },
				{ 1.0f, 1.0f, 0.0f },
				{ 1.0f, 1.0f, 1.0f },
				{ 1.0f, 0.0f, 1.0f }
			},
			.uvs = {
				{ 0, 1 },
				{ 0, 0 },
				{ 1, 0 },
				{ 1, 1 }
			},
			.face = EBlockFace::Side
		},
	};
};