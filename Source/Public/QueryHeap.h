#pragma once
#include "Core.h"
#include "Device.h"
#include "DxUtil.h"
#include "Types.h"
#include <d3d12.h>
#include <d3dx12.h>
#include <span>
#include <Windows.h>
#include <wrl/client.h>



template<EQueryHeapType>
struct QueryHeapTraits;

template<>
struct QueryHeapTraits <EQueryHeapType::Occlusion>
{
	using DataType = uint64;
	static constexpr D3D12_QUERY_HEAP_TYPE DxHeapType = D3D12_QUERY_HEAP_TYPE_OCCLUSION;
};

template<>
struct QueryHeapTraits <EQueryHeapType::Timestamp>
{
	using DataType = uint64;
	static constexpr D3D12_QUERY_HEAP_TYPE DxHeapType = D3D12_QUERY_HEAP_TYPE_TIMESTAMP;
};

template<>
struct QueryHeapTraits <EQueryHeapType::PipelineStatistics>
{
	using DataType = D3D12_QUERY_DATA_PIPELINE_STATISTICS1;
	static constexpr D3D12_QUERY_HEAP_TYPE DxHeapType = D3D12_QUERY_HEAP_TYPE_PIPELINE_STATISTICS1;
};

template<>
struct QueryHeapTraits <EQueryHeapType::StreamOutputStatistics>
{
	using DataType = D3D12_QUERY_DATA_SO_STATISTICS;
	static constexpr D3D12_QUERY_HEAP_TYPE DxHeapType = D3D12_QUERY_HEAP_TYPE_SO_STATISTICS;
};

template<>
struct QueryHeapTraits <EQueryHeapType::CopyQueueTimestamp>
{
	using DataType = uint64;
	static constexpr D3D12_QUERY_HEAP_TYPE DxHeapType = D3D12_QUERY_HEAP_TYPE_COPY_QUEUE_TIMESTAMP;
};

template <EQueryHeapType HeapType>
class QueryHeap
{
public:

	using HeapTraits = QueryHeapTraits<HeapType>;

	QueryHeap(Device& device, uint32 count)
	{
		D3D12_QUERY_HEAP_DESC desc{
			.Type = HeapTraits::DxHeapType,
			.Count = count,
			.NodeMask = 0
		};

		DxCall(device.GetDxDevice()->CreateQueryHeap(&desc, IID_PPV_ARGS(&mDxQueryHeap)));

		CD3DX12_HEAP_PROPERTIES heapProps(D3D12_HEAP_TYPE_READBACK);
		CD3DX12_RESOURCE_DESC bufferDesc = CD3DX12_RESOURCE_DESC::Buffer(sizeof(HeapTraits::DataType) * count);

		DxCall(device.GetDxDevice()->CreateCommittedResource(
			&heapProps,
			D3D12_HEAP_FLAG_NONE,
			&bufferDesc,
			D3D12_RESOURCE_STATE_COPY_DEST,
			nullptr,
			IID_PPV_ARGS(&mDxReadbackBuffer)
		));

		DxCall(mDxReadbackBuffer->Map(0, nullptr, reinterpret_cast<void**>(&mQueryData)));
	}

	~QueryHeap()
	{
		mDxReadbackBuffer->Unmap(0, nullptr);
	}


	QueryHeap(const QueryHeap&) = delete;

	QueryHeap& operator=(const QueryHeap&) = delete;

	QueryHeap(QueryHeap&&) = delete;

	QueryHeap& operator=(QueryHeap&&) = delete;

public:

	[[nodiscard]] FORCEINLINE ID3D12QueryHeap* GetDxQueryHeap() const noexcept { return mDxQueryHeap.Get(); }

	[[nodiscard]] FORCEINLINE ID3D12Resource* GetDxReadbackBufferResource() const noexcept { return mDxReadbackBuffer.Get(); }

	[[nodiscard]] std::span<typename const HeapTraits::DataType> GetQueryData(uint64 index, uint64 size) const { return { mQueryData + index, size }; }

protected:

	Microsoft::WRL::ComPtr<ID3D12QueryHeap> mDxQueryHeap;

	Microsoft::WRL::ComPtr<ID3D12Resource> mDxReadbackBuffer;

	HeapTraits::DataType* mQueryData;
};