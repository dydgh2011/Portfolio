#include "Monster1.h"

void Monster1::Initialize()
{
	SetBox(64, 64);
	iscollider = true;
	isgravity = true;
	isphysic = true;
	SetMass(100);

}

void Monster1::Progress()
{
	Object* Monster1 = OC.FindObject("Player");
	if (Monster1 == nullptr) return;
	// A - B / B -> A
	/*double _x = Monster1->x - x;
	double _y = Monster1->y - y;
	double _z = sqrt(_x * _x + _y * _y);
	_x = _x / _z;
	_y = _y / _z;*/
	wait += Time.Delta();
	if(wait >= 3&&wait<6)
	Translate(150 * Time.Delta(), 0);
	if (wait >= 6)
	Translate(-150 * Time.Delta(), 0);
	if (wait >= 7)
		wait = 0;
}
