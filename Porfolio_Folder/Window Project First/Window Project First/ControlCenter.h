#pragma once
#include<Windows.h>
#include<string>
#include<list>
#include"Control.h"

class ControlCenter
{
private:
	list<Control*> center;
public:
	Control* GetControl(DWORD id);
	void Push(Control* data);
	void WindowMessage(DWORD id, DWORD event);
	void InsertEvent(DWORD id, DWORD event, function<void(ControlCenter&)> func);
public:
	~ControlCenter();
};

