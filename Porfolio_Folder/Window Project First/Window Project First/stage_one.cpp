#include "stage_one.h"
#include "Timer.h"
#include "Monster1.h"
#include "ObjectCenter.h"
#include "stage_two.h"
#include "ground.h"
#include "questionbox.h"
#include "Player.h"
#include "Flag.h"
extern Timer Time;
extern ObjectCenter OC;

void stage_one::Initialize()
{
	objectname = "Stage";
	killed = 0;
	w = h = -1;
	x = y = -9999999;
	ChangeAnimation("None");

	regentime = 0;
	regen_fix = 0.5;
    Object* qb = new questionbox();
    qb->MoveTo(200,500);
    qb->SetName("question_box");
    qb->ChangeAnimation("mario_block_question_box");
    OC.PushObject(qb);

    Object* A = new Player();
    A->MoveTo(100, 500);
    A->SetName("Player");
    OC.PushObject(A);

    //OC.PushObject(new stage_one());

    for (int i = 0; i < 1000; ++i) {
        Object* box = new ground();
        box->MoveTo(0 + (i % 200) * 160, 900 + (i / 200) * 160);
        OC.PushObject(box);
    }
    for (int i = 0; i < 200; ++i) {
        Object* road = new ground();
        road->MoveTo(500 + 160 * i, 500);
        OC.PushObject(road);
    }
    for (int i = 0; i < 20; ++i) {
        Object* road = new ground();
        road->MoveTo(100 - 160 * i, 300);
        OC.PushObject(road);
    }
    for (int i = 0; i < 20; ++i) {
        Object* road = new ground();
        road->MoveTo(500 + 160 * i, -100);
        OC.PushObject(road);
    }
    for (int i = 0; i < 20; ++i) {
        Object* road = new ground();
        road->MoveTo(200 - 160 * i, -500);
        OC.PushObject(road);
    }
   for (int in = 0; in < 10; ++in) {
        Object* goomba = new Monster1();
        goomba->MoveTo(200*in, 200);
        goomba->SetName("goomba");
        goomba->ChangeAnimation("goomba_walking");
        OC.PushObject(goomba);
    }
   for (int in = 0; in < 10; ++in) {
       Object* goomba = new Monster1();
       goomba->MoveTo(520 * in, -170);
       goomba->SetName("goomba");
       goomba->ChangeAnimation("goomba_walking");
       OC.PushObject(goomba);
   }
   for (int in = 0; in < 40; ++in) {
       Object* goomba = new Monster1();
       goomba->MoveTo(520 +(70* in), 170);
       goomba->SetName("goomba");
       goomba->ChangeAnimation("goomba_walking");
       OC.PushObject(goomba);
   }
    Object* breakable = new questionbox();
    breakable->MoveTo(600, 100);
    breakable->ChangeAnimation("mario_block_unbrokable");
    OC.PushObject(breakable);

    Object* flag = new Flag();
    flag->MoveTo(-100, -111);
    OC.PushObject(flag);
}

void stage_one::Progress()
{
	/*regentime += Time.Delta();
	if (regentime > regen_fix) {
		regentime = 0;

		Object* Monsterf = new Monster1();
		Monsterf->MoveTo(RandInt(200,800), RandInt(200,800));
		Monsterf->SetName("Monster1s");
		Monsterf->ChangeAnimation("walking");
		OC.PushObject(Monsterf);
	}
	if (killed > 20) {
		OC.DeleteObject(this);
		OC.PushObject(new stage_two());
	}*/
   
}
