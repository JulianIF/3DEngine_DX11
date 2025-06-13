#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/ShaderBinary.h>

dx3d::GraphicsPipelineState::GraphicsPipelineState(const GraphicsPipelineStateDesc& desc, const GraphicResourcesDesc& gDesc) : GraphicResources(gDesc)
{
	if (desc.vs.getType() != ShaderType::VertexShader)
		DX3DLogThrowInvalidArg("vs is not a Vertex Shader");

	if (desc.ps.getType() != ShaderType::PixelShader)
		DX3DLogThrowInvalidArg("ps is not a Pixel Shader");

	auto vs = desc.vs.getData();
	DX3DGraphicsLogThrowOnFail(_device.CreateVertexShader(vs.data, vs.dataSize, NULL, &_vs), "Create Vertex Shader Failed");

	auto ps = desc.ps.getData();
	DX3DGraphicsLogThrowOnFail(_device.CreatePixelShader(ps.data, ps.dataSize, NULL, &_ps), "Create Pixel Shader Failed");

	constexpr D3D11_INPUT_ELEMENT_DESC elements[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};
	DX3DGraphicsLogThrowOnFail(_device.CreateInputLayout(elements, std::size(elements), vs.data, vs.dataSize, &_inputLayout), "CreateInputLayout Failed");

}

