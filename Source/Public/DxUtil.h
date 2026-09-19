#pragma once

#include "Types.h"
#include <d3d12.h>
#include <d3dcommon.h>
#include <DirectXMath.h>
#include <dxgiformat.h>
#include <intrin.h>
#include <string>
#include <string_view>
#include <thread>
#include <Windows.h>
#include <wrl/client.h>

inline std::wstring AnsiToWString(const std::string& str)
{
	WCHAR buffer[512];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, buffer, 512);
	return std::wstring(buffer);
}


#ifndef DxCall
#define DxCall(x)													\
{																			\
	HRESULT hr__ = (x);														\
	std::wstring fileName__ = AnsiToWString(__FILE__);						\
	if (FAILED(hr__)) { throw DxException(hr__, L""#x, fileName__, __LINE__); }	\
}
#endif


#ifndef NDEBUG
#include <format>
#define ensure(expr) \
        do { \
            if (!(expr)) { \
                auto msg = std::format("[ensure FAILED] Thread {} failed: {} at {}:{} in function {}\n", \
                                       std::this_thread::get_id(), \
                                       #expr, \
                                       __FILE__, \
                                       __LINE__, \
                                       __FUNCTION__); \
                OutputDebugStringA(msg.c_str()); \
                __debugbreak(); \
            } \
        } while(false)
#else
#define ensure(expr) ((void)0)
#endif


#define STRUCT_OFFSET(s,m) ((::size_t)&reinterpret_cast<char const volatile&>((((s*)0)->m)))


enum class EQueryHeapType
{
	Occlusion,
	Timestamp,
	PipelineStatistics,
	StreamOutputStatistics,
	CopyQueueTimestamp
};



template<typename T>
struct DxgiFormat;

template<>
struct DxgiFormat<float>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R32_FLOAT;
};

template<>
struct DxgiFormat<int8>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R8_SINT;
};

template<>
struct DxgiFormat<uint8>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R8_UINT;
};

template<>
struct DxgiFormat<int16>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R16_SINT;
};

template<>
struct DxgiFormat<uint16>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R16_UINT;
};

template<>
struct DxgiFormat<int32>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R32_SINT;
};

template<>
struct DxgiFormat<uint32>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R32_UINT;
};

template<>
struct DxgiFormat<Vector2D>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R32G32_FLOAT;
};

template<>
struct DxgiFormat<Vector3D>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R32G32B32_FLOAT;
};

template<>
struct DxgiFormat<Color>
{
	static constexpr DXGI_FORMAT value = DXGI_FORMAT_R8G8B8A8_UNORM;
};

namespace BlendPresets
{
	constexpr D3D12_RENDER_TARGET_BLEND_DESC Opaque = {
		.BlendEnable = FALSE,
		.LogicOpEnable = FALSE,

		.SrcBlend = D3D12_BLEND_ONE,
		.DestBlend = D3D12_BLEND_ZERO,
		.BlendOp = D3D12_BLEND_OP_ADD,

		.SrcBlendAlpha = D3D12_BLEND_ONE,
		.DestBlendAlpha = D3D12_BLEND_ZERO,
		.BlendOpAlpha = D3D12_BLEND_OP_ADD,

		.LogicOp = D3D12_LOGIC_OP_NOOP,
		.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL
	};

	constexpr D3D12_RENDER_TARGET_BLEND_DESC Alpha = {
		.BlendEnable = TRUE,
		.LogicOpEnable = FALSE,

		.SrcBlend = D3D12_BLEND_SRC_ALPHA,
		.DestBlend = D3D12_BLEND_INV_SRC_ALPHA,
		.BlendOp = D3D12_BLEND_OP_ADD,

		.SrcBlendAlpha = D3D12_BLEND_ONE,
		.DestBlendAlpha = D3D12_BLEND_INV_SRC_ALPHA,
		.BlendOpAlpha = D3D12_BLEND_OP_ADD,

		.LogicOp = D3D12_LOGIC_OP_NOOP,
		.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL
	};

	constexpr D3D12_RENDER_TARGET_BLEND_DESC Additive = {
		.BlendEnable = TRUE,
		.LogicOpEnable = FALSE,

		.SrcBlend = D3D12_BLEND_ONE,
		.DestBlend = D3D12_BLEND_ONE,
		.BlendOp = D3D12_BLEND_OP_ADD,

		.SrcBlendAlpha = D3D12_BLEND_ONE,
		.DestBlendAlpha = D3D12_BLEND_ONE,
		.BlendOpAlpha = D3D12_BLEND_OP_ADD,

		.LogicOp = D3D12_LOGIC_OP_NOOP,
		.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL
	};

	constexpr D3D12_RENDER_TARGET_BLEND_DESC UI = {
		.BlendEnable = TRUE,
		.LogicOpEnable = FALSE,

		.SrcBlend = D3D12_BLEND_SRC_ALPHA,
		.DestBlend = D3D12_BLEND_INV_SRC_ALPHA,
		.BlendOp = D3D12_BLEND_OP_ADD,

		.SrcBlendAlpha = D3D12_BLEND_ONE,
		.DestBlendAlpha = D3D12_BLEND_INV_SRC_ALPHA,
		.BlendOpAlpha = D3D12_BLEND_OP_ADD,

		.LogicOp = D3D12_LOGIC_OP_NOOP,
		.RenderTargetWriteMask =
			D3D12_COLOR_WRITE_ENABLE_RED |
			D3D12_COLOR_WRITE_ENABLE_GREEN |
			D3D12_COLOR_WRITE_ENABLE_BLUE
	};
};

namespace StaticSamplers
{
	constexpr D3D12_STATIC_SAMPLER_DESC PointWrap = {
		.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT,
		.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP,
		.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP,
		.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP,
		.MipLODBias = 0.0f,
		.MaxAnisotropy = 16,
		.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS,
		.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE,
		.MinLOD = 0.0f,
		.MaxLOD = D3D12_FLOAT32_MAX,
		.ShaderRegister = 0,
		.RegisterSpace = 0,
		.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL
	};

	constexpr D3D12_STATIC_SAMPLER_DESC PointClamp = {
		.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT,
		.AddressU = D3D12_TEXTURE_ADDRESS_MODE_CLAMP,
		.AddressV = D3D12_TEXTURE_ADDRESS_MODE_CLAMP,
		.AddressW = D3D12_TEXTURE_ADDRESS_MODE_CLAMP,
		.MipLODBias = -0.25f,
		.MaxAnisotropy = 16,
		.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS,
		.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE,
		.MinLOD = 0.0f,
		.MaxLOD = D3D12_FLOAT32_MAX,
		.ShaderRegister = 1,
		.RegisterSpace = 0,
		.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL
	};

	constexpr D3D12_STATIC_SAMPLER_DESC LinearWrap = {
		.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR,
		.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP,
		.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP,
		.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP,
		.MipLODBias = 0.0f,
		.MaxAnisotropy = 16,
		.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS,
		.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE,
		.MinLOD = 0.0f,
		.MaxLOD = D3D12_FLOAT32_MAX,
		.ShaderRegister = 2,
		.RegisterSpace = 0,
		.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL
	};

	constexpr D3D12_STATIC_SAMPLER_DESC LinearClamp = {
		.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR,
		.AddressU = D3D12_TEXTURE_ADDRESS_MODE_CLAMP,
		.AddressV = D3D12_TEXTURE_ADDRESS_MODE_CLAMP,
		.AddressW = D3D12_TEXTURE_ADDRESS_MODE_CLAMP,
		.MipLODBias = 0.0f,
		.MaxAnisotropy = 16,
		.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS,
		.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE,
		.MinLOD = 0.0f,
		.MaxLOD = D3D12_FLOAT32_MAX,
		.ShaderRegister = 3,
		.RegisterSpace = 0,
		.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL
	};

	constexpr D3D12_STATIC_SAMPLER_DESC AnisotropicWrap = {
		.Filter = D3D12_FILTER_ANISOTROPIC,
		.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP,
		.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP,
		.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP,
		.MipLODBias = 0.0f,
		.MaxAnisotropy = 8,
		.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS,
		.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE,
		.MinLOD = 0.0f,
		.MaxLOD = D3D12_FLOAT32_MAX,
		.ShaderRegister = 4,
		.RegisterSpace = 0,
		.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL
	};

	constexpr D3D12_STATIC_SAMPLER_DESC AnisotropicClamp = {
		.Filter = D3D12_FILTER_ANISOTROPIC,
		.AddressU = D3D12_TEXTURE_ADDRESS_MODE_CLAMP,
		.AddressV = D3D12_TEXTURE_ADDRESS_MODE_CLAMP,
		.AddressW = D3D12_TEXTURE_ADDRESS_MODE_CLAMP,
		.MipLODBias = 0.0f,
		.MaxAnisotropy = 8,
		.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS,
		.BorderColor = D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE,
		.MinLOD = 0.0f,
		.MaxLOD = D3D12_FLOAT32_MAX,
		.ShaderRegister = 5,
		.RegisterSpace = 0,
		.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL
	};
}


class DxException
{
public:

	DxException(HRESULT hr, const std::wstring& functionName, const std::wstring& fileName, int lineNumber);

	std::wstring ToWString() const noexcept;

protected:

	HRESULT mHRes;
	std::wstring mFunctionName;
	std::wstring mFileName;
	int mLineNumber;

};

namespace DxUtil
{
	[[nodiscard]] constexpr size_t GetConstBufferSize(size_t byteSize)
	{
		return (byteSize + 255) & ~255;
	}

	[[nodiscard]] constexpr uint64 AlignTo(uint64 size, uint64 alignment)
	{
		return (size + alignment - 1) & ~(alignment - 1);
	}

	[[nodiscard]] static DirectX::XMFLOAT4X4 Identity4x4()
	{
		static DirectX::XMFLOAT4X4 I(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);

		return I;
	}

	[[nodiscard]] static DirectX::XMFLOAT4 QuaternionIdentity()
	{
		static DirectX::XMFLOAT4 I(0.0f, 0.0f, 0.0f, 1.0f);
		return I;
	}

	[[nodiscard]] Microsoft::WRL::ComPtr<ID3DBlob> CompileShader(
		std::wstring_view filename,
		const D3D_SHADER_MACRO* defines,
		std::string_view entrypoint,
		std::string_view target
	);

	[[nodiscard]] std::string GetStringFromWCHAR(const WCHAR* wStr, int size = -1);



}