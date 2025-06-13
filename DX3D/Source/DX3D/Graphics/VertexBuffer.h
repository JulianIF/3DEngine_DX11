#pragma once

#include <DX3D/Graphics/GraphicResources.h>

namespace dx3d
{
	class VertexBuffer final : public GraphicResources
	{
	public:
		VertexBuffer(const VertexBufferDesc& desc, const GraphicResourcesDesc& gDesc);
		uint32_t getVertexListSize() const noexcept;
	private: 

		Microsoft::WRL::ComPtr<ID3D11Buffer> _buffer;
		uint32_t _vertexSize{};
		uint32_t _vertexListSize{};
		friend class DeviceContext;
	};
}

