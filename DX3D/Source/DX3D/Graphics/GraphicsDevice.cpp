#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/ShaderBinary.h>
#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/VertexBuffer.h>

dx3d::GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc& desc) : Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif 

	DX3DGraphicsLogThrowOnFail(D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION, &_d3dDevice, &featureLevel, &_d3dContext), "Direct 3D 11 Initialization Failed");

	DX3DGraphicsLogThrowOnFail(_d3dDevice->QueryInterface(IID_PPV_ARGS(&_dxgiDevice)), "Query Interface failed to retrieve IDXGI device");
	DX3DGraphicsLogThrowOnFail(_dxgiDevice->GetParent(IID_PPV_ARGS(&_dxgiAdapter)), "GetParent failed to retrieve IDXGI adapter");
	DX3DGraphicsLogThrowOnFail(_dxgiAdapter->GetParent(IID_PPV_ARGS(&_dxgiFactory)), "GetParent failed to retrieve IDXGI factory");

}

dx3d::GraphicsDevice::~GraphicsDevice()
{
}

dx3d::SwapChainPtr dx3d::GraphicsDevice::createSwapChain(const SwapChainDesc& desc) const
{
	return std::make_shared<SwapChain>(desc, getGraphicResourcesDesc());
}

dx3d::DeviceContextPtr dx3d::GraphicsDevice::createDeviceContext()
{
	return std::make_shared<DeviceContext>(getGraphicResourcesDesc());
}

dx3d::ShaderBinaryPtr dx3d::GraphicsDevice::compileShader(const ShaderCompileDesc& sDesc)
{
	return std::make_shared<ShaderBinary>(sDesc, getGraphicResourcesDesc());
}

dx3d::GraphicsPipelineStatePtr dx3d::GraphicsDevice::createGraphicsPipelineState(const GraphicsPipelineStateDesc& desc)
{
	return std::make_shared<GraphicsPipelineState>(desc, getGraphicResourcesDesc());
}

dx3d::VertexBufferPtr dx3d::GraphicsDevice::createVertexBuffer(const VertexBufferDesc& desc)
{
	return std::make_shared<VertexBuffer>(desc, getGraphicResourcesDesc());
}

void dx3d::GraphicsDevice::executeCommandList(DeviceContext& context)
{
	Microsoft::WRL::ComPtr<ID3D11CommandList> list{};
	DX3DGraphicsLogThrowOnFail(context._context->FinishCommandList(false, &list), "FinishCommandList Failed");
	_d3dContext->ExecuteCommandList(list.Get(), false);
}

dx3d::GraphicResourcesDesc dx3d::GraphicsDevice::getGraphicResourcesDesc() const noexcept
{
	return { {_logger} , shared_from_this(), *_d3dDevice.Get(), *_dxgiFactory.Get() };
}


