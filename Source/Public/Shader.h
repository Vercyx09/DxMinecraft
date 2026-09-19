#pragma once
#include "Core.h"
#include <cstddef>
#include <d3dcommon.h>
#include <span>
#include <string_view>
#include <wrl/client.h>

class Shader
{
public:

	void CompileFromFile(
		std::wstring_view filename,
		std::string_view entrypoint,
		std::string_view target,
		const D3D_SHADER_MACRO* defines = nullptr
	);

	[[nodiscard]] FORCEINLINE std::span<const std::byte> GetByteCode() const
	{
		return {
			reinterpret_cast<std::byte*>(mDxByteCode->GetBufferPointer()),
			mDxByteCode->GetBufferSize()
		};
	}

protected:

	Microsoft::WRL::ComPtr<ID3DBlob> mDxByteCode;
};

class VertexShader : public Shader {};
class PixelShader : public Shader {};
class DomainShader : public Shader {};
class HullShader : public Shader {};
class GeometryShader : public Shader {};