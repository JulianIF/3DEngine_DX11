#include <DX3D/Window/Window.h>
#include <Windows.h>
#include <stdexcept>

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return 0;
}






dx3d::Window::Window(const WindowDesc& desc) : Base(desc.base), _size(desc.size)
{
	auto registerWindowClassFunction = []()
		{
			WNDCLASSEX wc{};
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.lpszClassName = L"DX3DWindow";
			wc.lpfnWndProc = &WindowProcedure;
			return RegisterClassEx(&wc);
		};


	static const auto windowClassId = std::invoke(registerWindowClassFunction);


	if (!windowClassId)
	{
		DX3DLogThrowError("RegisterClassEx failed.");
	}

	RECT rc{ 0,0,_size.width,_size.height };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	_handle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"3DEngine DirectX11 | C++",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top,
		NULL, NULL, NULL, NULL);

	if (!_handle)
	{
		DX3DLogThrowError("CreateWindowEx failed.");
	}

	ShowWindow(static_cast<HWND>(_handle), SW_SHOW);
}

dx3d::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(_handle));
}
