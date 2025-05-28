#include <DX3D/Game/Display.h>
#include <DX3D/Graphics/RenderSystem.h>

dx3d::Display::Display(const DisplayDesc& desc) : Window(desc.window)
{
	_swapChain = desc.renderSystem.createSwapChain({ _handle, _size });
}
