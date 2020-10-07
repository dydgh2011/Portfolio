#pragma once
#include "Object.h"
#include "Timer.h"
#include "ObjectCenter.h"

extern Timer Time;
extern ObjectCenter OC;

class Monster1 :
	public Object
{

	double wait = 0;
	virtual void Initialize();
	virtual void Progress();
};

