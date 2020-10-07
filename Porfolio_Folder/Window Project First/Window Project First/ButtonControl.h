#pragma once
#include "Control.h"
class ButtonControl :
    public Control
{
public:
    ButtonControl(string value, int x, int y, int cx, int xy, int id);
};

