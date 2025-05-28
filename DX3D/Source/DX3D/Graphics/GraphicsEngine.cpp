#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/RenderSystem.h>

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	_renderSystem = std::make_shared<RenderSystem>(RenderSystemDesc{_logger});
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}

dx3d::RenderSystem& dx3d::GraphicsEngine::getRenderSystem() const noexcept
{
	return *_renderSystem;
}
