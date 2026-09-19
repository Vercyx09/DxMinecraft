#include "DxUtil.h"
#include <comdef.h>
#include <d3dcommon.h>
#include <D3Dcompiler.h>
#include <format>
#include <string>
#include <string_view>
#include <Types.h>
#include <Windows.h>
#include <wrl/client.h>

using namespace Microsoft::WRL;

#ifdef _DEBUG
#define SHADER_COMPILE_FLAGS (D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION)
#else
#define SHADER_COMPILE_FLAGS 0
#endif


DxException::DxException(HRESULT hr, const std::wstring& functionName, const std::wstring& fileName, int lineNumber)
	:
	mHRes(hr),
	mFunctionName(functionName),
	mFileName(fileName),
	mLineNumber(lineNumber)
{
}

std::wstring DxException::ToWString() const noexcept
{
	_com_error comError(mHRes);
	return std::format(L"{} failed in {}, line {}\n. Error: {}",
		mFunctionName,
		mFileName,
		std::to_wstring(mLineNumber),
		comError.ErrorMessage());
}

namespace DxUtil
{
	ComPtr<ID3DBlob> CompileShader(
		std::wstring_view filename,
		const D3D_SHADER_MACRO* defines,
		std::string_view entrypoint,
		std::string_view target)
	{
		ComPtr<ID3DBlob> byteCode = nullptr;
		ComPtr<ID3DBlob> errorBlob = nullptr;

		HRESULT hr = D3DCompileFromFile(
			filename.data(),
			defines,
			D3D_COMPILE_STANDARD_FILE_INCLUDE,
			entrypoint.data(),
			target.data(),
			SHADER_COMPILE_FLAGS,
			0,
			&byteCode,
			&errorBlob
		);

		if (errorBlob != nullptr)
		{
			OutputDebugStringA((char*)errorBlob->GetBufferPointer());
		}
		DxCall(hr);


		return byteCode;
	}

	std::string GetStringFromWCHAR(const WCHAR* wStr, int size)
	{
		if (!wStr)
		{
			return std::string{};
		}

		int required = size;
		if (required <= 0)
		{
			required = WideCharToMultiByte(
				CP_UTF8,
				0,
				wStr,
				-1,
				nullptr,
				0,
				nullptr,
				nullptr
			);

			if (required <= 0)
			{
				return std::string{};
			}
		}

		// `required` includes space for the terminating null
		std::string result;
		result.resize(required); // reserve room for null

		int written = WideCharToMultiByte(
			CP_UTF8,
			0,
			wStr,
			-1,
			&result[0],
			required,
			nullptr,
			nullptr
		);

		if (written <= 0)
		{
			return std::string{};
		}

		// `written` includes the terminating null, remove it from the std::string length
		result.resize(written - 1);
		return result;
	}	
}
