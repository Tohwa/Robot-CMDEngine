#pragma once

#include "Platform.h"

namespace Robot {

	class MacOSPlatform : public Platform
	{
		virtual void SetCursorPosition(const Vec2& pos) override;
		virtual void ClearScreen() override;
	};

}
