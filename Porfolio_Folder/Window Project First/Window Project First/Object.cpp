#include "Object.h"
#include "AnimationCenter.h"
#include "SpriteCenter.h"
#include "Timer.h"
#include "ScrollCenter.h"

extern AnimationCenter AC;
extern SpriteCenter SC;
extern Timer Time;
extern ScrollCenter Cam;

void MassEffect(Object* Mine, Object* Other, double left, double top, double right, double bottom)
{
    if (Mine->mass == 0 && Other->mass == 0) return;
    double wg = right - left;
    double hg = bottom - top;
    if (Mine->mass == 0) {
        if (wg < hg) {
            if (Mine->x < Other->x) Other->Translate(wg, 0);
            else Other->Translate(-wg, 0);
        }
        else {
            if (Mine->y < Other->y) Other->Translate(0, hg);
            else { Other->Translate(0, -hg); Other->diry = 0; }
        }
    }
    else if (Other->mass == 0) {
        if (wg < hg) {
            if (Mine->x > Other->x) Mine->Translate(wg, 0);
            else Mine->Translate(-wg, 0);
        }
        else {
            if (Mine->y > Other->y) Mine->Translate(0, hg);
            else { Mine->Translate(0, -hg); Mine->diry = 0; }
        }
    }
    else {
        if (wg < hg) {
            double mass_mine = (double)Mine->mass / (double)(Mine->mass + Other->mass);
            double mass_other = (double)Other->mass / (double)(Mine->mass + Other->mass);
            if (Mine->x < Other->x) {
                Mine->Translate(-mass_other * wg, 0);
                Other->Translate(mass_mine * wg, 0);
            }
            else {
                Mine->Translate(mass_other * wg, 0);
                Other->Translate(-mass_mine * wg, 0);
            }
        }
        else {
            double mass_mine = (double)Mine->mass / (double)(Mine->mass + Other->mass);
            double mass_other = (double)Other->mass / (double)(Mine->mass + Other->mass);
            if (Mine->y < Other->y) {
                Mine->Translate(0, -mass_other * hg);
                Other->Translate(0, mass_mine * hg);
                Mine->diry = 0;
            }
            else {
                Mine->Translate(0, mass_other * hg);
                Other->Translate(0, -mass_mine * hg);
                Other->diry = 0;
            }
        }
    }
}

void Object::AddForce(double x, double y)
{
    dirx += x;
    diry += y;
}

bool Object::CollideBox(Object* Other)
{
    double   left_mine = x - w / 2;
    double    top_mine = y - h / 2;
    double  right_mine = x + w / 2;
    double bottom_mine = y + h / 2;

    double   left_other = Other->x - Other->w / 2;
    double    top_other = Other->y - Other->h / 2;
    double  right_other = Other->x + Other->w / 2;
    double bottom_other = Other->y + Other->h / 2;

    if (left_mine < right_other && left_other < right_mine &&
        top_mine < bottom_other && top_other < bottom_mine)
    {
        if (isphysic)
        {
            if (Other->isphysic)
            {
                MassEffect(this, Other,
                    (left_mine < left_other) ? left_other : left_mine,
                    (top_mine < top_other) ? top_other : top_mine, 
                    (left_mine < left_other) ? right_mine : right_other,
                    (top_mine < top_other) ? bottom_mine : bottom_other);
            }
        }
        return true;
    }
	return false;
}

void Object::Translate(float x, float y)
{
    this->x += x;
    this->y += y;
}

void Object::MoveTo(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Object::ChangeAnimation(std::string key)
{
    if (key == "None") {
        anim = "None"; return;
    }
    if (anim == key) return;
    anim = key;
    animindex = AC.Check(anim, -1);
}

void Object::PhysicProgress()
{
    if (isgravity) {
        diry += 1500 * Time.Delta();
    }

    Translate(dirx * Time.Delta(), diry * Time.Delta());
    dirx -= Time.Delta() * dirx * 0.6;
    diry -= Time.Delta() * diry * 0.6;
    if (dirx < 1 && dirx > -1) dirx = 0;
    if (diry < 1 && diry > -1) diry = 0;
}

Object::Object(std::string objectname)
	:objectname(objectname), x(0),y(0),anim(""),animindex(0)
    ,iscollider(false), isphysic(false), isgravity(false)
    ,w(0),h(0), mass(0), dirx(0), diry(0)
{}

void Object::Progress()
{
}

#define __DEBUG_MODE_SETTING__

void Object::Render()
{
    double x = (this->x - Cam.GetX() + 600);
    double y = (this->y - Cam.GetY() + 600);
    if (x < -100 || x > 1300 || y < -100 || y > 1300) return;
    if (anim == "None") return;
    SC[AC[anim]->scNumber]->DrawSlice(SC.DrawDC, 
        x - SC[AC[anim]->scNumber]->GetSliceIndex(animindex).right / 2,
        y - SC[AC[anim]->scNumber]->GetSliceIndex(animindex).bottom / 2,
        animindex);
    animindex = AC.Check(anim, ++animindex);
#ifdef __DEBUG_MODE_SETTING__
    double   left_mine = x - w / 2;
    double    top_mine = y - h / 2;
    double  right_mine = x + w / 2;
    double bottom_mine = y + h / 2;
    MoveToEx(SC.DrawDC, left_mine, top_mine, nullptr);
    LineTo(SC.DrawDC, right_mine, top_mine);
    LineTo(SC.DrawDC, right_mine, bottom_mine);
    LineTo(SC.DrawDC, left_mine, bottom_mine);
    LineTo(SC.DrawDC, left_mine, top_mine);
#endif
}

int RandInt(int min, int max)
{
    std::random_device rn;
    std::mt19937_64 rnd(rn());
    std::uniform_int_distribution<int> range(min, max);
    return range(rnd);
}
