#pragma once
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Base.h>

namespace dx3d
{
	class GraphicsEngine final : public Base
	{
	public: 
		explicit GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;

		GraphicsDevice& getGraphicsDevice() const noexcept;
	private:
		std::shared_ptr<GraphicsDevice> _graphicsDevice{};
	};
}

