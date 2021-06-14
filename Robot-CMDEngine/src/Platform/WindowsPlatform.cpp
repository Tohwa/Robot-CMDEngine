#include "Core.h"

#ifdef ROBOT_PLATFORM_WINDOWS

#include "WindowsPlatform.h"

#include <Windows.h>

namespace Robot {

	void WindowsPlatform::SetCursorPosition(const Vec2& pos)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position = { pos.x, pos.y };
		std::cout.flush();
		SetConsoleCursorPosition(hConsole, position);
	}

	void WindowsPlatform::SetTerminalSize(const Vec2& size)
	{
		if (m_CurrentSize == size) return;

		printf("mode con cols=%i lines=%i", size.x, size.y);

		m_CurrentSize = size;
	}

	void WindowsPlatform::ClearScreen()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO info;

		std::cout.flush();

		GetConsoleScreenBufferInfo(hConsole, &info);

		COORD reset = { 0, 0 };
		DWORD written;

		FillConsoleOutputCharacter(hConsole, TEXT(' '), info.dwSize.X * info.dwSize.Y, reset, &written);
		SetConsoleCursorPosition(hConsole, reset);
	}

}

#endif