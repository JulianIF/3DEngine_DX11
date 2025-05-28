#include <DX3D/Game/Display.h>
#include <DX3D/Graphics/GraphicsDevice.h>

dx3d::Display::Display(const DisplayDesc& desc) : Window(desc.window)
{
	_swapChain = desc.graphicsDevice.createSwapChain({ _handle, _size });
}
