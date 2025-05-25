#include <DX3D/Graphics/RenderSystem.h>

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc) : Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif 

	auto hr = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION, &_d3dDevice, &featureLevel, &_d3dContext);

	if (FAILED(hr))
	{
		getLogger().log(Logger::LogLevel::Error, "Direct 3D 11 Initialization Failed");
		throw std::runtime_error("Direct 3D 11 Initialization Failed");
	}
}

dx3d::RenderSystem::~RenderSystem()
{
}
