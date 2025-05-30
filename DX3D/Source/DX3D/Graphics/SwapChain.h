#pragma once
#include <DX3D/Graphics/GraphicResources.h>

namespace dx3d
{
	class SwapChain final : public GraphicResources
	{
	public:
		SwapChain(const SwapChainDesc& desc, const GraphicResourcesDesc& gDesc);

		void present(bool vsync = false);

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> _swapChain{};
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _renderTargetView{};

		void reloadBuffers();

		friend class DeviceContext;
	};
}

