#pragma once
#include "Control.h"
class DialogControl :
	public Control
{
public:
	DialogControl(int x, int y, int cx, int xy, int id, WNDPROC proc);
};

