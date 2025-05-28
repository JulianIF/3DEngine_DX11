#pragma once
#include <DX3D/Core/Core.h>

namespace dx3d
{
	class Rect
	{
	public:
		Rect() = default;
		Rect(int width, int height) : left(0), top(0), width(width), height(height) {};
		Rect(int left, int top, int width, int height) : left(left), top(top), width(width), height(height) {};

		int left{}, top{}, width{}, height{};
	};
}