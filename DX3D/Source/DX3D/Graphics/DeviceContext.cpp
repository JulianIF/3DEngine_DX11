#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/GraphicsPipelineState.h>

dx3d::DeviceContext::DeviceContext(const GraphicResourcesDesc& gDesc) : GraphicResources(gDesc)
{
	DX3DGraphicsLogThrowOnFail(_device.CreateDeferredContext(0, &_context), "Failed to create Deferred Context");
}

void dx3d::DeviceContext::clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color)
{
	float fColor[] = { color.x, color.y, color.z, color.w };
	auto rtv = swapChain._renderTargetView.Get();
	_context->ClearRenderTargetView(rtv, fColor);
	_context->OMSetRenderTargets(1, &rtv, NULL);
}

void dx3d::DeviceContext::setGraphicsPipelineState(const GraphicsPipelineState& pipeline)
{
	_context->VSSetShader(pipeline._vs.Get(), nullptr, 0);
	_context->PSSetShader(pipeline._ps.Get(), nullptr, 0);
}
