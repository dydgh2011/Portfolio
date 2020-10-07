#pragma once
#include "Control.h"
class StaticControl :
    public Control
{
public:
    StaticControl(string value,int x, int y, int cx, int xy, int id);
    StaticControl(HWND parent, string value, int x, int y, int cx, int xy, int id);
};

