#include "stage_two.h"
#include "Timer.h"
#include "ObjectCenter.h"
#include "Monster2.h"
extern Timer Time;
extern ObjectCenter OC;

void stage_two::Initialize()
{
	w = h = -1;
	x = y = -9999999;
	ChangeAnimation("None");

	regentime = 0;
	regen_fix = 0.5;
}

void stage_two::Progress()
{
}