#include "Monster2.h"
#include"ObjectCenter.h"
#include "Timer.h"

extern ObjectCenter OC;
extern Timer Time;

void Monster2::Initialize()
{
	SetBox(64, 64);
	iscollider = true;
	isgravity= true;
}

void Monster2::Progress()
{
	//Object* Monster1 = OC.FindObject("Monster1s");
	//if (Monster1 == nullptr) return;
	//// A - B / B -> A
	//double _x = Monster1->x - x;
	//double _y = Monster1->y - y;
	//double _z = sqrt(_x * _x + _y * _y);
	//_x = _x / _z;
	//_y = _y / _z;

	//Translate(_x * 150 * Time.Delta(), _y * 150 * Time.Delta());
}
