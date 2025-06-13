#pragma once
#include <DX3D/Graphics/GraphicResources.h>

namespace dx3d
{
	class GraphicsPipelineState final : public GraphicResources
	{
	public:
		GraphicsPipelineState(const GraphicsPipelineStateDesc& desc, const GraphicResourcesDesc& gDesc);

	private:
		Microsoft::WRL::ComPtr<ID3D11VertexShader> _vs{};
		Microsoft::WRL::ComPtr<ID3D11PixelShader> _ps{};
		Microsoft::WRL::ComPtr<ID3D11InputLayout> _inputLayout{};

		friend class DeviceContext;
	};
}

