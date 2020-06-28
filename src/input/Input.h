#pragma once

#include "../Core.h"

//CAPS LOCK, CONTROL, SHIFT nur für windows implementiert

//ESC
#define ROBOT_KEY_ESC 0

//Numbers
#define ROBOT_KEY_0 1
#define ROBOT_KEY_1 2
#define ROBOT_KEY_2 3
#define ROBOT_KEY_3 4
#define ROBOT_KEY_4 5
#define ROBOT_KEY_5 6
#define ROBOT_KEY_6 7
#define ROBOT_KEY_7 8
#define ROBOT_KEY_8 9
#define ROBOT_KEY_9 10

//Alphabeth
#define ROBOT_KEY_A 11
#define ROBOT_KEY_B 12
#define ROBOT_KEY_C 13
#define ROBOT_KEY_D 14
#define ROBOT_KEY_E 15
#define ROBOT_KEY_F 16
#define ROBOT_KEY_G 17
#define ROBOT_KEY_H 18
#define ROBOT_KEY_I 19
#define ROBOT_KEY_J 20
#define ROBOT_KEY_K 21
#define ROBOT_KEY_L 22
#define ROBOT_KEY_M 23
#define ROBOT_KEY_N 24
#define ROBOT_KEY_O 25
#define ROBOT_KEY_P 26
#define ROBOT_KEY_Q 27
#define ROBOT_KEY_R 28
#define ROBOT_KEY_S 29
#define ROBOT_KEY_T 30
#define ROBOT_KEY_U 31
#define ROBOT_KEY_V 32
#define ROBOT_KEY_W 33
#define ROBOT_KEY_X 34
#define ROBOT_KEY_Y 35
#define ROBOT_KEY_Z 36

//Control Keys
#define ROBOT_KEY_TAB 37
#define ROBOT_KEY_BACK 38
#define ROBOT_KEY_CAPS_LOCK 39
#define ROBOT_KEY_LEFT_SHIFT 40
#define ROBOT_KEY_LEFT_CONTROL 41
#define ROBOT_KEY_ENTER 43
#define ROBOT_KEY_RIGHT_SHIFT 44
#define ROBOT_KEY_RIGHT_CONTROL 45

#ifdef ROBOT_PLATFORM_WINDOWS
	#define GET_KEY_PRESSED(key) GetAsyncKeyState(key) < 0
	#define KEY_RETURN_TYPE int
#endif

namespace Robot {

	struct Input
	{
		static bool IsKeyPressed(KEY_RETURN_TYPE key);

		static KEY_RETURN_TYPE ConvertToOSKeyCode(int keycode);
	};

}
