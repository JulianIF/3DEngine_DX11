#pragma once
#include <DX3D/Graphics/GraphicResources.h>

namespace dx3d
{
	class SwapChain final : public GraphicResources
	{
	public:
		SwapChain(const SwapChainDesc& desc, const GraphicResourcesDesc& gDesc);

		void present(bool vsync = false);
		Rect getSize() const noexcept;
	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> _swapChain{};
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _renderTargetView{};
		Rect _size{};
		void reloadBuffers();

		friend class DeviceContext;
	};
}

