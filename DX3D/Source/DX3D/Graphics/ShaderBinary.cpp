#include <DX3D/Graphics/ShaderBinary.h>
#include <d3dcompiler.h>
#include <DX3D/Graphics/GraphicUtils.h>

dx3d::ShaderBinary::ShaderBinary(const ShaderCompileDesc& sDesc, const GraphicResourcesDesc& gDesc) : GraphicResources(gDesc), _type(sDesc.shaderType)
{

	if (!sDesc.shaderSourceName) DX3DLogThrowInvalidArg("No shader source name provided");
	if (!sDesc.shaderSourceCode) DX3DLogThrowInvalidArg("No shader source code provided");
	if (!sDesc.shaderEntryPoint) DX3DLogThrowInvalidArg("No shader entry point provided");
	if (!sDesc.shaderSourceCodeSize) DX3DLogThrowInvalidArg("No shader source code size provided");

	UINT compileFlags{};

#ifdef _DEBUG
	compileFlags |= D3DCOMPILE_DEBUG;
#endif 

	Microsoft::WRL::ComPtr<ID3DBlob> errorBlob{};

	DX3DGraphicsCheckShaderCompile(
		D3DCompile(
			sDesc.shaderSourceCode,
			sDesc.shaderSourceCodeSize,
			sDesc.shaderSourceName,
			nullptr,
			nullptr,
			sDesc.shaderEntryPoint,
			dx3d::GraphicUtils::GetShaderModelTarget(sDesc.shaderType),
			compileFlags,
			0,
			&_blob,
			&errorBlob
		),
		errorBlob.Get()
	);


}

dx3d::ShaderBinaryData dx3d::ShaderBinary::getData() const noexcept
{
	return
	{
		_blob->GetBufferPointer(),
		_blob->GetBufferSize()
	};
}

dx3d::ShaderType dx3d::ShaderBinary::getType() const noexcept
{
	return _type;
}
