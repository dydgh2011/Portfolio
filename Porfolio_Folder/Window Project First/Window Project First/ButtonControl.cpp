#include "ButtonControl.h"

ButtonControl::ButtonControl(string value, int x, int y, int cx, int xy, int id)
	:Control("button", value, WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, x, y, cx, xy, id)
{
}
