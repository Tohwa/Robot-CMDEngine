#include "Core.h"

#ifdef ROBOT_PLATFORM_MACOS

#include "MacOSPlatform.h"

#include <iostream>

namespace Robot {

	void MacOSPlatform::SetCursorPosition(const Vec2& pos)
	{
		printf("%c[%d;%df", 0x1B, pos.x, pos.y);
	}

	void MacOSPlatform::ClearScreen()
	{
		system("clear");
	}

}

#endif