#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/VertexBuffer.h>

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
	_context->IASetInputLayout(pipeline._inputLayout.Get());
	_context->VSSetShader(pipeline._vs.Get(), nullptr, 0);
	_context->PSSetShader(pipeline._ps.Get(), nullptr, 0);
}

void dx3d::DeviceContext::setVertexBuffer(const VertexBuffer& buffer)
{
	auto stride = buffer._vertexSize;
	auto buf = buffer._buffer.Get();
	auto offset = 0u;

	_context->IASetVertexBuffers(0, 1, &buf, &stride, &offset);
}

void dx3d::DeviceContext::setViewportSize(const Rect& size)
{
	D3D11_VIEWPORT vp{};
	vp.Width = static_cast<float>(size.width);
	vp.Height = static_cast<float>(size.height);
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;

	_context->RSSetViewports(1, &vp);
}

void dx3d::DeviceContext::drawTriangleList(uint32_t vertexCount, uint32_t startVertexLocation)
{
	_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	_context->Draw(vertexCount, startVertexLocation);
}
