#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Math/Vec3.h>
#include <DX3D/Graphics/VertexBuffer.h>

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{_logger});

	auto& device = *_graphicsDevice;
	_deviceContext = device.createDeviceContext();

	constexpr char shaderSourceCode[] =
		R"(
float4 VSMain(float3 pos: POSITION): SV_Position
{
	return float4 (pos.xyz, 1.0f);
}
float4 PSMain(): SV_Target
{
	return float4 (1.0f, 1.0f, 1.0f, 1.0f);
}
)";
	constexpr char shaderSourceName[] = "Basic";
	constexpr auto shaderSourceCodeSize = std::size(shaderSourceCode);

	auto vs = device.compileShader({shaderSourceName, shaderSourceCode, shaderSourceCodeSize, "VSMain", ShaderType::VertexShader});

	auto ps = device.compileShader({ shaderSourceName, shaderSourceCode, shaderSourceCodeSize, "PSMain", ShaderType::PixelShader });

	_pipeline = device.createGraphicsPipelineState({ *vs, *ps });

	const Vec3 vertexList[] =
	{
		{-0.5f, -0.5f, 0.0f},
		{0.0f, 0.5f, 0.0f},
		{0.5f, -0.5f, 0.0f}
	};

	_vertexBuffer = device.createVertexBuffer({ vertexList, std::size(vertexList), sizeof(Vec3) });
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}

dx3d::GraphicsDevice& dx3d::GraphicsEngine::getGraphicsDevice() noexcept
{
	return *_graphicsDevice;
}

void dx3d::GraphicsEngine::render(SwapChain& swapChain)
{
	auto& context = *_deviceContext;
	context.clearAndSetBackBuffer(swapChain, { 1,0,0,1 });
	context.setGraphicsPipelineState(*_pipeline);

	context.setViewportSize(swapChain.getSize());

	auto& vb = *_vertexBuffer;
	context.setVertexBuffer(vb);
	context.drawTriangleList(vb.getVertexListSize(), 0u);

	auto& device = *_graphicsDevice;
	device.executeCommandList(context);

	swapChain.present();
}
