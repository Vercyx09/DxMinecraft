#include "Shader.h"
#include "DxUtil.h"
#include <d3dcommon.h>
#include <string_view>

void Shader::CompileFromFile(std::wstring_view filename, std::string_view entrypoint, std::string_view target, const D3D_SHADER_MACRO* defines)
{
	mDxByteCode = DxUtil::CompileShader(filename, defines, entrypoint, target);
}
