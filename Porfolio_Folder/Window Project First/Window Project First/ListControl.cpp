#include "ListControl.h"

ListControl::ListControl(int x, int y, int cx, int xy, int id, UINT option)
	:Control("listbox", "", WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY | option, x, y, cx, xy, id)
{}
