#include "Input.h"

namespace Robot {

	bool Input::IsKeyPressed(KEY_RETURN_TYPE key)
	{
		if (GET_KEY_PRESSED(ConvertToOSKeyCode(key)))
		{
			return true;
		}

		return false;
	}

	KEY_RETURN_TYPE Input::ConvertToOSKeyCode(int keycode)
	{
#		ifdef ROBOT_PLATFORM_WINDOWS
		switch (keycode)
		{
			case ROBOT_KEY_ESC: return VK_ESCAPE;

			case ROBOT_KEY_0: return 0x30;
			case ROBOT_KEY_1: return 0x31;
			case ROBOT_KEY_2: return 0x32;
			case ROBOT_KEY_3: return 0x33;
			case ROBOT_KEY_4: return 0x34;
			case ROBOT_KEY_5: return 0x35;
			case ROBOT_KEY_6: return 0x36;
			case ROBOT_KEY_7: return 0x37;
			case ROBOT_KEY_8: return 0x38;
			case ROBOT_KEY_9: return 0x39;

			case ROBOT_KEY_A: return 0x41;
			case ROBOT_KEY_B: return 0x42;
			case ROBOT_KEY_C: return 0x43;
			case ROBOT_KEY_D: return 0x44;
			case ROBOT_KEY_E: return 0x45;
			case ROBOT_KEY_F: return 0x46;
			case ROBOT_KEY_G: return 0x47;
			case ROBOT_KEY_H: return 0x48;
			case ROBOT_KEY_I: return 0x49;
			case ROBOT_KEY_J: return 0x4A;
			case ROBOT_KEY_K: return 0x4B;
			case ROBOT_KEY_L: return 0x4C;
			case ROBOT_KEY_M: return 0x4D;
			case ROBOT_KEY_N: return 0x4E;
			case ROBOT_KEY_O: return 0x4F;
			case ROBOT_KEY_P: return 0x50;
			case ROBOT_KEY_Q: return 0x51;
			case ROBOT_KEY_R: return 0x52;
			case ROBOT_KEY_S: return 0x53;
			case ROBOT_KEY_T: return 0x54;
			case ROBOT_KEY_U: return 0x55;
			case ROBOT_KEY_V: return 0x56;
			case ROBOT_KEY_W: return 0x57;
			case ROBOT_KEY_X: return 0x58;
			case ROBOT_KEY_Y: return 0x59;
			case ROBOT_KEY_Z: return 0x5A;

			case ROBOT_KEY_TAB: return VK_TAB;
			case ROBOT_KEY_BACK: return VK_BACK;
			case ROBOT_KEY_CAPS_LOCK: return VK_CAPITAL;
			case ROBOT_KEY_LEFT_SHIFT: return VK_SHIFT;
			case ROBOT_KEY_LEFT_CONTROL: return VK_CONTROL;
			case ROBOT_KEY_ENTER: return VK_RETURN;
			case ROBOT_KEY_RIGHT_SHIFT: return VK_SHIFT;
			case ROBOT_KEY_RIGHT_CONTROL: return VK_CONTROL;
		}
		#endif
		return 0;
	}



}