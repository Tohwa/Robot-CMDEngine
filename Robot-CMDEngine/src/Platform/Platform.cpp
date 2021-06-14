#include "Platform.h"

#ifdef ROBOT_PLATFORM_WINDOWS
	#include "WindowsPlatform.h"

#elif defined(ROBOT_PLATFORM_LINUX)
	#include "LinuxPlatform.h"

#elif defined(ROBOT_PLATFORM_MACOS)
	#include "MacOSPlatform.h"
#endif

namespace Robot {

	Ref<Platform> Platform::m_Platform = nullptr;

	void Platform::create_platform()
	{
		#ifdef ROBOT_PLATFORM_WINDOWS
			m_Platform = std::make_shared<WindowsPlatform>();
		#elif defined(ROBOT_PLATFORM_LINUX)
			m_Platform = std::make_shared<LinuxPlatform>();
		#elif defined(ROBOT_PLATFORM_MACOS)
			m_Platform = std::make_shared<MacOSPlatform>();
		#endif
	}

	Ref<Platform> Platform::get_platform()
	{
		if (m_Platform == nullptr)
			create_platform();

		return m_Platform;
	}

}