#pragma once
namespace dx3d
{
	class Vec4
	{
	public: 
		Vec4() = default;
		Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

		float x{}, y{}, z{}, w{};
	};
}