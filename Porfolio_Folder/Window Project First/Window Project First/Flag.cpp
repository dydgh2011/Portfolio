#include "Flag.h"
#include "Timer.h"
#include "ObjectCenter.h"
#include "Input.h"
#include "stage_one.h"

extern Timer Time;
extern ObjectCenter OC;
extern Input KEY;

void Flag::Initialize()
{
	iscollider = false;
	ChangeAnimation("flag");
	objectname = "flag";
	SetBox(282, 349);
	isphysic = false;
	SetMass(0);
}

void Flag::Progress()
{

}

void Flag::CollideStay(Object* Other)
{
}
