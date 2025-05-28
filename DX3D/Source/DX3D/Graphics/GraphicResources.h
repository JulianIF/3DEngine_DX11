#pragma once
#include <DX3D/Core/Common.h>
#include <DX3D/Core/Base.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>
#include <d3d11.h>
#include <wrl.h>

namespace dx3d
{
	struct GraphicResourcesDesc
	{
		BaseDesc base;
		std::shared_ptr<const RenderSystem> renderSystem;
		ID3D11Device& device;
		IDXGIFactory& factory;
	};

	class GraphicResources : public Base
	{
	public:
		explicit GraphicResources(const GraphicResourcesDesc& desc):
			Base(desc.base),
			_renderSystem(desc.renderSystem),
			_device(desc.device),
			_factory(desc.factory)
		{

		}

	protected:
		std::shared_ptr<const RenderSystem> _renderSystem;
		ID3D11Device& _device;
		IDXGIFactory& _factory;
	};
}