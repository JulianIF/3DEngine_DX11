#pragma once
namespace dx3d
{
	class Vec3
	{
	public:
		Vec3() = default;
		Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
		float x{}, y{}, z{};
	};
}