#include "StaticControl.h"
StaticControl::StaticControl(string value, int x, int y, int cx, int xy, int id)
	:Control("static",value, WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, x, y, cx, xy, id)
{
}

StaticControl::StaticControl(HWND parent, string value, int x, int y, int cx, int xy, int id)
	: Control(parent, "static", value, WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, x, y, cx, xy, id)
{
}
