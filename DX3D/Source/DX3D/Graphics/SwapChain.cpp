#include <DX3D/Graphics/SwapChain.h>

dx3d::SwapChain::SwapChain(const SwapChainDesc& desc, const GraphicResourcesDesc& gDesc) : GraphicResources(gDesc), _size(desc.winSize)
{
	if (!desc.winHandle) DX3DLogThrowInvalidArg("No window handle provided");

	DXGI_SWAP_CHAIN_DESC dxgiDesc{};

	dxgiDesc.BufferDesc.Width = std::max(1, desc.winSize.width);
	dxgiDesc.BufferDesc.Height = std::max(1, desc.winSize.height);
	dxgiDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; //4 Color Chanells Normalized Unsigned ints 8 bits
	dxgiDesc.BufferCount = 2;
	dxgiDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	dxgiDesc.OutputWindow = static_cast<HWND>(desc.winHandle);
	dxgiDesc.SampleDesc.Count = 1;
	dxgiDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	dxgiDesc.Windowed = TRUE;

	DX3DGraphicsLogThrowOnFail(_factory.CreateSwapChain(&_device, &dxgiDesc, &_swapChain), "CreateSwapChain failed");

	reloadBuffers();
}

void dx3d::SwapChain::present(bool vsync)
{
	DX3DGraphicsLogThrowOnFail(_swapChain->Present(vsync, 0), "Present Failed");
}

dx3d::Rect dx3d::SwapChain::getSize() const noexcept
{
	return _size;
}

void dx3d::SwapChain::reloadBuffers()
{
	Microsoft::WRL::ComPtr<ID3D11Texture2D> buffer{};
	DX3DGraphicsLogThrowOnFail(_swapChain->GetBuffer(0, IID_PPV_ARGS(&buffer)), "GetBuffer Failed");

	DX3DGraphicsLogThrowOnFail(_device.CreateRenderTargetView(buffer.Get(), nullptr, &_renderTargetView), "CreateRenderTargetView Failed");


}


