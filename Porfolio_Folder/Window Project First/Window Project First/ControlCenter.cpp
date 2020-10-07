#include "ControlCenter.h"

Control* ControlCenter::GetControl(DWORD id)
{
    for (auto iter = center.begin();
        iter != center.end(); ++iter) {
        if ((*iter)->GetID() == id) {
            return *iter;
        }
    }
    return nullptr;
}

void ControlCenter::Push(Control* data)
{
	center.push_back(data);
}

void ControlCenter::WindowMessage(DWORD id, DWORD event)
{
    for (auto iter = center.begin();
        iter != center.end(); ++iter) {
        if ((*iter)->GetID() == id) {
            (*iter)->CallEvent(event, *this);
        }
    }
    //switch (LOWORD(wParam)) {
    //case 1:
    //    switch (HIWORD(wParam)) {
    //    case BN_CLICKED:
    //        char temp[200], temp2[200];
    //        GetWindowTextA(hEditL, temp2, 200);
    //        GetWindowTextA(hEditR, temp, 200);
    //        int n;
    //        n = _atoi64(temp) + _atoi64(temp2);
    //        _itoa_s(n, temp, 200, 10);
    //        SetWindowTextA(hStatic, temp);
    //        break;
    //    }
    //    break;
    //case 2:
    //    switch (HIWORD(wParam)) {
    //    case BN_CLICKED:
    //        char temp[200], temp2[200];
    //        GetWindowTextA(hEditL, temp, 200);
    //        GetWindowTextA(hEditR, temp2, 200);
    //        int n;
    //        n = _atoi64(temp) - _atoi64(temp2);
    //        _itoa_s(n, temp, 200, 10);
    //        SetWindowTextA(hStatic, temp);
    //        break;
    //    }
    //    break;
    //case 3:
    //    switch (HIWORD(wParam)) {
    //    case BN_CLICKED:
    //        char temp[200], temp2[200];
    //        GetWindowTextA(hEditL, temp2, 200);
    //        GetWindowTextA(hEditR, temp, 200);
    //        int n;
    //        n = _atoi64(temp) * _atoi64(temp2);
    //        _itoa_s(n, temp, 200, 10);
    //        SetWindowTextA(hStatic, temp);
    //        break;
    //    }
    //    break;
    //case 4:
    //    switch (HIWORD(wParam)) {
    //    case BN_CLICKED:
    //        char temp[200], temp2[200];
    //        GetWindowTextA(hEditL, temp, 200);
    //        GetWindowTextA(hEditR, temp2, 200);
    //        double n;
    //        double p;
    //        n = atof(temp) / atof(temp2);
    //        _itoa_s(n, temp, 200, 10);
    //        //ftoa ?
    //        SetWindowTextA(hStatic, temp);
    //        break;
    //    }
    //    break;
    //case ID_EDIT_LEFT:
    //case ID_EDIT_RIGHT:
    //    break;
    //}
}

void ControlCenter::InsertEvent(DWORD id, DWORD event, function<void(ControlCenter&)> func)
{
    for (auto iter = center.begin();
        iter != center.end(); ++iter) {
        if ((*iter)->GetID() == id) {
            (*iter)->PushEvent(event, func);
        }
    }
}

ControlCenter::~ControlCenter()
{
	for (auto iter = center.begin();
		iter != center.end(); ++iter) {
		delete* iter;
	}
	center.clear();
}
