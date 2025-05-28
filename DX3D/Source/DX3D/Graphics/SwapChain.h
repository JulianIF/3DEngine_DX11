#pragma once
#include <DX3D/Graphics/GraphicResources.h>

namespace dx3d
{
	class SwapChain final : public GraphicResources
	{
	public:
		SwapChain(const SwapChainDesc& desc, const GraphicResourcesDesc& gDesc);

		
	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> _swapChain{};
	};
}

