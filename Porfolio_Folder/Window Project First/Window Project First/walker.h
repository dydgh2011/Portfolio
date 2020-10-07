#pragma once
#include "Object.h"
#include "Timer.h"
#include "ObjectCenter.h"


extern Timer Time;
extern ObjectCenter OC;

class walker :
	public Object
{
	virtual void Progress();
};

