#pragma once
#include <DX3D/Graphics/GraphicResources.h>
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Base.h>
#include <d3d11.h>
#include <wrl.h>

namespace dx3d
{
	class GraphicsDevice final: public Base, public std::enable_shared_from_this<GraphicsDevice>
	{
	public:
		explicit GraphicsDevice(const GraphicsDeviceDesc& desc);
		virtual ~GraphicsDevice() override;
		SwapChainPtr createSwapChain(const SwapChainDesc& desc) const;
		DeviceContextPtr createDeviceContext();
		ShaderBinaryPtr compileShader(const ShaderCompileDesc& sDesc);
		GraphicsPipelineStatePtr createGraphicsPipelineState(const GraphicsPipelineStateDesc& desc);
		void executeCommandList(DeviceContext& context);
	private: 
		GraphicResourcesDesc getGraphicResourcesDesc() const noexcept;
		Microsoft::WRL::ComPtr<ID3D11Device> _d3dDevice{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _d3dContext{};
		Microsoft::WRL::ComPtr<IDXGIDevice> _dxgiDevice{};
		Microsoft::WRL::ComPtr<IDXGIAdapter> _dxgiAdapter{};
		Microsoft::WRL::ComPtr<IDXGIFactory> _dxgiFactory{};
	};
}

