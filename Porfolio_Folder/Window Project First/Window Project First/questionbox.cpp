#include "questionbox.h"
#include "Timer.h"
#include "ObjectCenter.h"

extern Timer Time;
extern ObjectCenter OC;

void questionbox::Initialize()
{
	SetBox(160, 160);
	iscollider = true;
	isgravity = false;
	isphysic = true;
	SetMass(0);
}

void questionbox::Progress()
{
	//Object* player = OC.FindObject("Player");
	//if (player == nullptr) return;
	//// A - B / B -> A
	//double _x = player->x - x;
	//double _y = player->y - y;
	//double _z = sqrt(_x * _x + _y * _y);
	//_x = _x / _z;
	//_y = _y / _z;

	//Translate(_x * 250 * Time.Delta(), _y * 250 * Time.Delta());
}

