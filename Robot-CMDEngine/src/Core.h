#pragma once

#include <iostream>
#include <memory>
#include <string>

#ifdef _WIN32
	#define ROBOT_PLATFORM_WINDOWS
 
	#include <Windows.h>
	#include <conio.h>
#elif defined(__linux__)
	#define ROBOT_PLATFORM_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
	#define ROBOT_PLATFORM_MACOS
#endif


namespace Robot {

	template<typename T>
	using Ref = std::shared_ptr<T>;
	
}
