#pragma once
#include<Windows.h>
#include<string>
#include<functional>
#include<map>
using namespace std;
class ControlCenter;
class Control
{
private:
	HWND hControl;
	HWND hParentHandle = NULL;
	DWORD ID;
	map<DWORD, function<void(ControlCenter&)>> Event;
public:
	static HWND hWnd;
	static HINSTANCE hInst;
public:
	LRESULT Send(UINT Option, WPARAM wParam, LPARAM lParam) {
		return SendMessageA(hControl, Option, wParam, lParam);
	}
	LRESULT Getcount(UINT Option, WPARAM wParam, LPARAM lParam) {
		return  SendMessageA(hControl, Option, wParam, lParam);
	}
	HWND GetHandle() const {
		return hControl;
	}
	HWND GetParentHandle() const {
		return hParentHandle;
	}
	DWORD GetID() const {
		return ID;
	}
	void PushEvent(DWORD message, function<void(ControlCenter&)> func) {
		Event.insert(make_pair(message, func));
	}
	void CallEvent(DWORD message, ControlCenter& center) {
		if(Event.find(message) != Event.end())
			Event[message](center);
	}
public:
	Control(string type, string data, DWORD style, int x, int y, int cx, int cy, int id);
	Control(HWND parent, string type, string data, DWORD style, int x, int y, int cx, int cy, int id);
	Control(int x, int y, int cx, int cy, int id, WNDPROC proc);
};

