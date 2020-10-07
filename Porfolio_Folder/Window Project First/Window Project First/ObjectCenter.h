#pragma once

#include <Windows.h>
#include <list>
#include "Object.h"

class ObjectCenter
{
private:
	std::list<Object*> objects;
	std::list<Object*> remover;
	double fixed = 0;
private:
	bool IsIn(Object* obj);
public:
	void PushObject(Object* obj);
	void DeleteObject(Object* obj);
	void Progress();
	void Render();
	Object* FindObject(std::string find);
public:
	~ObjectCenter();
};

