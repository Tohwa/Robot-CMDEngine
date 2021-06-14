#pragma once

#include "Core.h"

#include "Math/BasicTypes.h"

namespace Robot {

	class Platform
	{
	public:
		virtual void SetCursorPosition(const Vec2& pos) = 0;
		virtual void SetTerminalSize(const Vec2& size) = 0;
		virtual void ClearScreen() = 0;
		
		static Ref<Platform> get_platform();

	private:
		static void create_platform();

	private:
		static Ref<Platform> m_Platform;
	};
}

