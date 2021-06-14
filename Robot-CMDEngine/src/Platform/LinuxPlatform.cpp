#include "Core.h"

#ifdef ROBOT_PLATFORM_LINUX

#include "LinuxPlatform.h"

#include <iostream>

namespace Robot {

	void LinuxPlatform::SetCursorPosition(const Vec2& pos)
	{
		printf("%c[%d;%df", 0x1B, pos.x, pos.y);
	}

	void LinuxPlatform::ClearScreen()
	{
		system("clear");
	}

}

#endif