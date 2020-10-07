#include "Player.h"
#include "Timer.h"
#include "ObjectCenter.h"
#include "Input.h"
#include "stage_one.h"
#include "ScrollCenter.h"
#include "Object.h"

extern Timer Time;
extern ObjectCenter OC;
extern Input KEY;
extern ScrollCenter Cam;

void Player::Initialize()
{
	ChangeAnimation("mario_right");
	SetBox(64, 128);
	iscollider = true;
	isphysic = true;
	isgravity = true;
	SetMass(300);
}

void Player::Progress()
{
	if (KEY.GetKeyDown(VK_UP)) {
		AddForce(0, -800);
	}

	if (KEY.GetKey(VK_RIGHT)) {
		Translate(200 * Time.Delta(), 0);
			ChangeAnimation("mario_right");
	}

	if (KEY.GetKey(VK_LEFT)) {
		Translate(-200 * Time.Delta(), 0);

		ChangeAnimation("mario_left");
	}

	if (!KEY.GetKey(VK_LEFT)&& !KEY.GetKey(VK_RIGHT)) {
		std::string temp = GetAnimation();
		if(temp.find("_stand") > 50000)
		{ 
			ChangeAnimation(GetAnimation() + "_stand");
		}
	}

	Cam.MoveTo(this->x, this->y);
}

void Player::CollideStay(Object* Other)
{
	if (Other->objectname == "question_box") {
		if (Other->y < y) {
			if (abs(x - Other->x) < w / 2) {
				OC.DeleteObject(Other);
			}
		}
	}
	if (Other->objectname == "goomba") {
		if (Other->y > y) {
			if (abs(x - Other->x) < w / 2) {
				AddForce(0, -900);
				OC.DeleteObject(Other);
			}
		}
	}
	if (Other->objectname == "flag") {
		if (Other->y < y || Other->y >y) {
			if (abs(x - Other->x) < w / 2) {
				OC.DeleteObject(Other);
			}
		}
	}
	/*OC.DeleteObject(Other);
	Object* stage = OC.FindObject("Stage");
	if (dynamic_cast<stage_one*>(stage)) {
		((stage_one*)stage)->killed++;
	}*/
}
