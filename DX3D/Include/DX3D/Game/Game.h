#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Core/Core.h>


namespace dx3d
{
	class Game: public Base
	{
	public:
		explicit Game(const GameDesc& desc);
		virtual ~Game() override;

		virtual void run() final;
	private:
		std::unique_ptr<Logger> _loggerPtr{};
		std::unique_ptr<GraphicsEngine> _graphicsEngine{};
		std::unique_ptr<Display> _display{};
		bool _isRunning{ true };
		void onInternalUpdate();
	};
}
