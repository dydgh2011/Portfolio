#include "ground.h"
#include "Timer.h"
#include "ObjectCenter.h"
#include "Input.h"
#include "stage_one.h"

extern Timer Time;
extern ObjectCenter OC;
extern Input KEY;

void ground::Initialize()
{
	iscollider = true;
	ChangeAnimation("mario_block_normal");
	objectname = "Block_Normal";
	SetBox(160, 160);
	isphysic = true;
	SetMass(0);
}

void ground::Progress()
{

}

void ground::CollideStay(Object* Other)
{
}
