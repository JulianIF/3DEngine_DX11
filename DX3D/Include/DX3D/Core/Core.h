#pragma once
#include <stdexcept>
#include <memory>

namespace dx3d
{
	class Base;
	class Window;
	class Game;

	class GraphicsEngine;
	class GraphicsDevice;

	class Logger;

	class SwapChain;

	class Display;
	class DeviceContext;
	class ShaderBinary;
	class GraphicsPipelineState;
	class VertexBuffer;

	using SwapChainPtr = std::shared_ptr<SwapChain>;
	using DeviceContextPtr = std::shared_ptr<DeviceContext>;
	using ShaderBinaryPtr = std::shared_ptr<ShaderBinary>;
	using GraphicsPipelineStatePtr = std::shared_ptr<GraphicsPipelineState>;
	using VertexBufferPtr = std::shared_ptr<VertexBuffer>;

}