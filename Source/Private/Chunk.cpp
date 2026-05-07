#include "BlockTexture.h"
#include "BlockTextureMapping.h"
#include "BlockType.h"
#include "Chunk.h"
#include "DxUtil.h"
#include "Renderer.h"
#include "Types.h"
#include "World.h"
#include <atomic>
#include <DirectXMathConvert.inl>
#include <DirectXMathMatrix.inl>
#include <memory>
#include <utility>
#include <vector>


[[nodiscard]] static Color GetTextureTint(EBlockType block, EBlockFace face)
{
	switch (block)
	{
	case EBlockType::GrassBlock:
	{
		if (face == EBlockFace::Top)
		{
			return Color{ 131, 187, 109, 255 };
		}
		break;
	}
	case EBlockType::Water:
		return Color{ 63, 118, 228, 255 };
	}
	return Color{ 255, 255, 255, 255 };
}

[[nodiscard]] static Color GetOverlayTextureTint(EBlockType block, [[maybe_unused]] EBlockFace face)
{
	switch (block)
	{
	case EBlockType::GrassBlock:
	{
		return Color{ 131, 187, 109, 255 };
	}
	case EBlockType::Water:
		return Color{ 63, 118, 228, 255 };
	}
	return Color{ 255, 255, 255, 255 };
}

static constexpr bool IsFaceVisible(
	int32 x, int32 y, int32 z,
	const std::shared_ptr<const std::vector<EBlockType>>& chunkData,
	const std::shared_ptr<const std::vector<EBlockType>>& westChunkData,
	const std::shared_ptr<const std::vector<EBlockType>>& eastChunkData,
	const std::shared_ptr<const std::vector<EBlockType>>& northChunkData,
	const std::shared_ptr<const std::vector<EBlockType>>& southChunkData)
{
	if (y < 0 || y >= CHUNK_HEIGHT)
	{
		return true;
	}

	if (x < 0)
	{
		return !westChunkData || westChunkData->empty() || (*westChunkData)[GetBlockIndex(CHUNK_SIZE - 1, y, z)] == EBlockType::Air;
	}

	if (x >= CHUNK_SIZE)
	{
		return !eastChunkData || eastChunkData->empty() || (*eastChunkData)[GetBlockIndex(0, y, z)] == EBlockType::Air;
	}

	if (z < 0)
	{
		return !northChunkData || northChunkData->empty() || (*northChunkData)[GetBlockIndex(x, y, CHUNK_SIZE - 1)] == EBlockType::Air;
	}

	if (z >= CHUNK_SIZE)
	{
		return !southChunkData || southChunkData->empty() || (*southChunkData)[GetBlockIndex(x, y, 0)] == EBlockType::Air;
	}

	return (*chunkData)[GetBlockIndex(x, y, z)] == EBlockType::Air;
}


Chunk::Chunk(World& world, ChunkCoordinates chunkCoordinates)
	:
	mWorld(world),
	mChunkCoordinates(chunkCoordinates)
{
	DirectX::XMStoreFloat4x4(&mWorldMatrix, DirectX::XMMatrixTranslation(mChunkCoordinates.x * static_cast<float>(CHUNK_SIZE), 0, mChunkCoordinates.y * static_cast<float>(CHUNK_SIZE)));
}


void Chunk::BuildChunkMesh()
{
	ensure(!mBuildingMesh);

	const auto blockData = std::atomic_load(&mBlockData);

	if (!blockData || blockData->empty())
	{
		return;
	}

	//ensure(!mRenderDataDirty);
	//ensure(blockData);
	//ensure(!blockData->empty());

	mBuildingMesh = true;

	std::shared_ptr<MeshData> newMesh = std::make_shared<MeshData>();

	newMesh->vertices.reserve(blockData->size() / 2);
	newMesh->indices.reserve(blockData->size() / 2);

	uint32 indexOffset = 0;

	std::shared_ptr<const std::vector<EBlockType>> westChunkData;
	if (std::shared_ptr<Chunk> westChunk = mWorld.GetChunkWeak({ mChunkCoordinates.x - 1, mChunkCoordinates.y }).lock())
	{
		westChunkData = westChunk->GetBlockData();
	}

	std::shared_ptr<const std::vector<EBlockType>> eastChunkData;
	if (std::shared_ptr<Chunk> eastChunk = mWorld.GetChunkWeak({ mChunkCoordinates.x + 1, mChunkCoordinates.y }).lock())
	{
		eastChunkData = eastChunk->GetBlockData();
	}

	std::shared_ptr<const std::vector<EBlockType>> northChunkData;
	if (std::shared_ptr<Chunk> northChunk = mWorld.GetChunkWeak({ mChunkCoordinates.x, mChunkCoordinates.y - 1 }).lock())
	{
		northChunkData = northChunk->GetBlockData();
	}

	std::shared_ptr<const std::vector<EBlockType>> southChunkData;
	if (std::shared_ptr<Chunk> southChunk = mWorld.GetChunkWeak({ mChunkCoordinates.x, mChunkCoordinates.y + 1 }).lock())
	{
		southChunkData = southChunk->GetBlockData();
	}


	for (uint32 y = 0; y < CHUNK_HEIGHT; ++y)
	{
		for (uint32 z = 0; z < CHUNK_SIZE; ++z)
		{
			for (uint32 x = 0; x < CHUNK_SIZE; ++x)
			{
				const EBlockType blockType = (*blockData)[GetBlockIndex(x, y, z)];

				if (blockType == EBlockType::Air)
				{
					continue;
				}

				for (int32 f = 0; f < 6; ++f)
				{
					// Coordinates of the adjacent block
					const int32 nx = x + static_cast<int32>(faces[f].normal.x);
					const int32 ny = y + static_cast<int32>(faces[f].normal.y);
					const int32 nz = z + static_cast<int32>(faces[f].normal.z);

					if (!IsFaceVisible(nx, ny, nz,
						blockData,
						westChunkData,
						eastChunkData,
						northChunkData,
						southChunkData
					))
					{
						continue;
					}

					const EBlockFace blockFace = faces[f].face;

					// Add vertices
					for (int32 v = 0; v < 4; ++v)
					{
						newMesh->vertices.emplace_back(BlockVertex{
							.position = {
								faces[f].vertices[v].x + static_cast<float>(x),
								faces[f].vertices[v].y + static_cast<float>(y),
								faces[f].vertices[v].z + static_cast<float>(z)
							},
							.normal = faces[f].normal,
							.textureOffset = static_cast<uint16>(GetBlockTexture(blockType, blockFace)),
							.overlayTextureOffset = static_cast<uint16>(GetBlockOverlayTexture(blockType, blockFace)),
							.textureUV = faces[f].uvs[v],
							.textureTint = GetTextureTint(blockType, blockFace),
							.overlayTextureTint = GetOverlayTextureTint(blockType, blockFace)
							});
					}

					// Add indices (two triangles)
					newMesh->indices.push_back(indexOffset + 0);
					newMesh->indices.push_back(indexOffset + 1);
					newMesh->indices.push_back(indexOffset + 2);
					newMesh->indices.push_back(indexOffset + 2);
					newMesh->indices.push_back(indexOffset + 3);
					newMesh->indices.push_back(indexOffset + 0);

					indexOffset += 4;
				}
			}
		}
	}

	std::atomic_store(&mMeshData, newMesh);
	mRenderDataDirty = true;

	mMeshBuilt = true;
	mBuildingMesh = false;
}

EBlockType Chunk::GetBlockAt(BlockCoordiantes coordinates) const
{
	if (const auto& blockData = GetBlockData())
	{
		return blockData->at(GetBlockIndex(coordinates.x, coordinates.y, coordinates.z));
	}
	return EBlockType::Air;
}

void Chunk::SetRenderData(std::unique_ptr<RenderData> renderData)
{
	mRenderData = std::move(renderData);
}




void Chunk::CreateRenderData()
{


}
