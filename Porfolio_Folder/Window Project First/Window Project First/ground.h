#pragma once
#include "Object.h"
class ground :
    public Object
{
	virtual void Initialize();
	virtual void Progress();
	virtual void CollideStay(Object* Other);
};

