#pragma once
#include <DX3D/Graphics/GraphicResources.h>
#include <DX3D/Math/Vec4.h>

namespace dx3d
{
	class DeviceContext final : public GraphicResources
	{
	public: 
		explicit DeviceContext(const GraphicResourcesDesc& gDesc);
		void clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color);
		void setGraphicsPipelineState(const GraphicsPipelineState& pipeline);
		void setVertexBuffer(const VertexBuffer& buffer);
		void setViewportSize(const Rect& size);
		void drawTriangleList(uint32_t vertexCount, uint32_t startVertexLocation);
	private:
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context{};

		friend class GraphicsDevice;
	};
}

