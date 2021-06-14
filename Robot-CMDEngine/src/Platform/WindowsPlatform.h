#pragma once

#include "Platform.h"

#include <string>

namespace Robot {

	class WindowsPlatform : public Platform
	{
		virtual void SetCursorPosition(const Vec2& pos) override;
		virtual void SetTerminalSize(const Vec2& size) override;
		virtual void ClearScreen() override;

	private:

		Vec2 m_CurrentSize;
	};

}
