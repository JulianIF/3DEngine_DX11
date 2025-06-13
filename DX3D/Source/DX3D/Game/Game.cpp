#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>
#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Core/Logger.h>
#include <DX3D/Game/Display.h>

dx3d::Game::Game(const GameDesc& desc) :
	Base({*std::make_unique<Logger>(desc.logLevel).release()}),
	_loggerPtr(&_logger)
{
	_graphicsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{_logger});
	_display = std::make_unique<Display>(DisplayDesc{ {_logger, desc.windowSize}, _graphicsEngine->getGraphicsDevice()});

	DX3DLogInfo("Game Initialized");
}

dx3d::Game::~Game()
{
	DX3DLogInfo("Game Ending and Deallocating");
}

void dx3d::Game::onInternalUpdate()
{
	_graphicsEngine->render(_display->getSwapChain());

}

