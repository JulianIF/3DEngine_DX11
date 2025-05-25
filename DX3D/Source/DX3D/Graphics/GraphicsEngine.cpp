#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/RenderSystem.h>

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	_renderSystem = std::make_unique<RenderSystem>(RenderSystemDesc{_logger});
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}
