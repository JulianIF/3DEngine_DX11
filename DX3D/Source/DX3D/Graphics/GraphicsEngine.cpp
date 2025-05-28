#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/GraphicsDevice.h>

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{_logger});
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}

dx3d::GraphicsDevice& dx3d::GraphicsEngine::getGraphicsDevice() const noexcept
{
	return *_graphicsDevice;
}
