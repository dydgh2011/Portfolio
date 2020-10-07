#include "EditControl.h"

EditControl::EditControl(int x, int y, int cx, int cy, int id)
	:Control("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,x,y,cx,cy,id)
{}

EditControl::EditControl(HWND parent, int x, int y, int cx, int cy, int id)
	: Control(parent, "edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, x, y, cx, cy, id)
{
}
