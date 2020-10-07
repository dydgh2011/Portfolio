#pragma once
#include "Object.h"
class stage_one :
	public Object
{
public:
	int killed;
	double regentime;
	double regen_fix;
public:
	virtual void Initialize();
	virtual void Progress();
};

