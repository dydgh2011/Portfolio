#pragma once
#include "Object.h"
class Flag :
	public Object
{
	virtual void Initialize();
	virtual void Progress();
	virtual void CollideStay(Object* Other);
};

