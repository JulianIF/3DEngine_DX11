#include <DX3D/Graphics/VertexBuffer.h>

dx3d::VertexBuffer::VertexBuffer(const VertexBufferDesc& desc, const GraphicResourcesDesc& gDesc) : GraphicResources(gDesc), _vertexSize(desc.vertexSize), _vertexListSize(desc.vertexListSize)
{
	if (!desc.vertexList) DX3DLogThrowInvalidArg("No vertexList provided");
	if (!desc.vertexListSize) DX3DLogThrowInvalidArg("No vertexListSize provided");
	if (!desc.vertexSize) DX3DLogThrowInvalidArg("No vertexSize provided");

	D3D11_BUFFER_DESC bufferDesc{};
	bufferDesc.ByteWidth = desc.vertexListSize * desc.vertexSize;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData{};
	initData.pSysMem = desc.vertexList;

	DX3DGraphicsLogThrowOnFail(_device.CreateBuffer(&bufferDesc, &initData, &_buffer), "CreateBuffer Failed");
}

uint32_t dx3d::VertexBuffer::getVertexListSize() const noexcept
{
	return _vertexListSize;
}
