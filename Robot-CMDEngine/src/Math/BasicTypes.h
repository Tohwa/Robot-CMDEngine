#pragma once


struct Vec2
{
	Vec2(int x = 0, int y = 0)
		: x(x), y(y) {}

	int x, y;

	bool operator==(const Vec2& other)
	{
		if (x == other.x && y == other.y)
			return true;
		return false;
	}
};