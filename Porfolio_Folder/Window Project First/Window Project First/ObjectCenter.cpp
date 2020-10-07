#include "ObjectCenter.h"
#include "Timer.h"
#include "ScrollCenter.h"

extern Timer Time;
extern ScrollCenter Cam;

bool ObjectCenter::IsIn(Object* obj)
{
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if (*iter == obj)
			return true;
	}
	return false;
}

void ObjectCenter::PushObject(Object* obj)
{
	objects.push_back(obj);
	obj->Initialize();
}

void ObjectCenter::DeleteObject(Object* obj)
{
	for (auto iter = remover.begin(); iter != remover.end(); ++iter){
		if (*iter == obj)
			return;
	}
	remover.push_back(obj);
}

void ObjectCenter::Progress()
{
	fixed += Time.Delta();

	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if ((*iter)->x - Cam.GetX() + 600 < -100 ||
			(*iter)->x - Cam.GetX() + 600 > 1300 ||
			(*iter)->y - Cam.GetY() + 600 < -100 ||
			(*iter)->y - Cam.GetY() + 600 > 1300) continue;
		(*iter)->PhysicProgress();
		(*iter)->Progress();
	}

	if (fixed >= 0.01) {
		fixed = 0;
		for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
			if (!(*iter)->IsCollider()) continue;
			if ((*iter)->x - Cam.GetX() + 600 < -100 ||
				(*iter)->x - Cam.GetX() + 600 > 1300 ||
				(*iter)->y - Cam.GetY() + 600 < -100 ||
				(*iter)->y - Cam.GetY() + 600 > 1300) continue;
			auto iternext = iter;
			++iternext;
			for (; iternext != objects.end(); ++iternext) {
				if (!(*iternext)->IsCollider()) continue;
				if ((*iternext)->x - Cam.GetX() + 600 < -100 ||
					(*iternext)->x - Cam.GetX() + 600 > 1300 ||
					(*iternext)->y - Cam.GetY() + 600 < -100 ||
					(*iternext)->y - Cam.GetY() + 600 > 1300) continue;
				if ((*iter)->CollideBox(*iternext)) {
					(*iter)->CollideStay(*iternext);
					(*iternext)->CollideStay(*iter);
				}
			}
		}
	}

	for (auto iter = remover.begin(); iter != remover.end(); ++iter) {
		objects.remove(*iter);
		delete *iter;
	}
	remover.clear();
}

void ObjectCenter::Render()
{
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		(*iter)->Render();
	}
}

Object* ObjectCenter::FindObject(std::string find)
{
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if ((*iter)->GetName() == find) return *iter;
	}
	return nullptr;
}

ObjectCenter::~ObjectCenter()
{
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		delete* iter;
	}
	objects.clear();
}
