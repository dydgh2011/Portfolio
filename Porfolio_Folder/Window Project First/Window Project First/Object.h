#pragma once

#include <Windows.h>
#include <string>
#include <random>

int RandInt(int min, int max);

class Object
{
public:
	float x, y;
	int mass;
	double dirx, diry;
	std::string anim, objectname;
	int animindex;
	bool iscollider, isphysic, isgravity;
	double w, h;
public:
	void AddForce(double x, double y);
	void SetBox(double w, double h) {
		this->w = w;
		this->h = h;
	}
	void SetMass(int mass = 1) {
		if (mass < 1) this->mass = 0;
		else this->mass = mass;
	}
	void SetName(std::string name) { objectname = name; }
	std::string GetName() const { return objectname; }
	bool IsCollider() const { return iscollider; }
	bool CollideBox(Object* Other);
	void Translate(float x, float y);
	void MoveTo(float x, float y);
	void ChangeAnimation(std::string key);
	void PhysicProgress();
	std::string GetAnimation() const { return anim; }
public:
	Object(std::string objectname = "GameObject");
public:
	virtual void CollideStay(Object* Other) {};
public:
	virtual void Initialize() {};
	virtual void Progress();
	void Render();
};

