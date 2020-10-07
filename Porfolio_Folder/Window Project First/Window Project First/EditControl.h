#pragma once
#include "Control.h"
class EditControl :
    public Control
{
public:
    EditControl(int x, int y, int cx, int cy, int id);
    EditControl(HWND parent, int x, int y, int cx, int cy, int id);
};


