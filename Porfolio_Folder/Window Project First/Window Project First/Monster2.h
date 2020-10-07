#pragma once
#include "Object.h"
#include "Timer.h"
#include "ObjectCenter.h"

extern Timer Time;
extern ObjectCenter OC;

class Monster2 :
	public Object
{
	virtual void Initialize();
	virtual void Progress();
};

