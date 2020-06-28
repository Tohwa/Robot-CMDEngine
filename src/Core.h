#pragma once

#include <iostream>

#ifdef _WIN32
	#define ROBOT_PLATFORM_WINDOWS
 
	#include <Windows.h>
	#include <conio.h>
#elif defined(__linux__)
	#error "Linux wird leider nicht unterstützt :("
#elif defined(__APPLE__) || defined(__MACH__)
	#error "Apple wird leider nicht unterstützt :("
#endif
