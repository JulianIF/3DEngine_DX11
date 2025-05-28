#include <DX3D/Graphics/RenderSystem.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>
#include <DX3D/Graphics/SwapChain.h>

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc) : Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif 

	DX3DGraphicsLogErrorAndThrow(D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION, &_d3dDevice, &featureLevel, &_d3dContext), "Direct 3D 11 Initialization Failed");

	DX3DGraphicsLogErrorAndThrow(_d3dDevice->QueryInterface(IID_PPV_ARGS(&_dxgiDevice)), "Query Interface failed to retrieve IDXGI device");
	DX3DGraphicsLogErrorAndThrow(_dxgiDevice->GetParent(IID_PPV_ARGS(&_dxgiAdapter)), "GetParent failed to retrieve IDXGI adapter");
	DX3DGraphicsLogErrorAndThrow(_dxgiAdapter->GetParent(IID_PPV_ARGS(&_dxgiFactory)), "GetParent failed to retrieve IDXGI factory");

}

dx3d::RenderSystem::~RenderSystem()
{
}

dx3d::SwapChainPtr dx3d::RenderSystem::createSwapChain(const SwapChainDesc& desc) const
{
	return std::make_shared<SwapChain>(desc, getGraphicResourcesDesc());
}

dx3d::GraphicResourcesDesc dx3d::RenderSystem::getGraphicResourcesDesc() const noexcept
{
	return { {_logger} , shared_from_this(), *_d3dDevice.Get(), *_dxgiFactory.Get() };
}
