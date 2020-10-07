#include "Input.h"

void Input::Progress()
{
	for (int i = VK_LBUTTON; i <= VK_OEM_CLEAR; ++i) {
		if (GetAsyncKeyState(i) & 0x8000) {
			if (keys[i].Press == false) 
				keys[i].BeforePress = true;
			else 
				keys[i].BeforePress = false;
			keys[i].Press = true;
		}
		else {
			keys[i].BeforePress = false;
			keys[i].Press = false;
		}
	}
}
