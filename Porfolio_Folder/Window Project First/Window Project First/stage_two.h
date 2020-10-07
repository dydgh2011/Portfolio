#pragma once
#include "Object.h"
class stage_two :
	public Object
{
	public:
		double regentime;
		double regen_fix;
	public:
		virtual void Initialize();
		virtual void Progress();
};

