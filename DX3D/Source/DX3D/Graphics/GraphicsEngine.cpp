#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{_logger});

	auto& device = *_graphicsDevice;
	_deviceContext = device.createDeviceContext();
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

	auto& device = *_graphicsDevice;
	device.executeCommandList(context);

	swapChain.present();
}
