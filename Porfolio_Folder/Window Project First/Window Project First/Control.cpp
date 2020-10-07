#include "Control.h"

Control::Control(string type, string data, DWORD style, int x, int y, int cx, int cy, int id)
{
    ID = id;
    hControl = CreateWindowA(type.c_str(), (data == "") ? NULL : data.c_str(), style,
        x, y, cx, cy, hWnd, (HMENU)id, hInst, NULL);
}

Control::Control(HWND parent, string type, string data, DWORD style, int x, int y, int cx, int cy, int id)
{
    ID = id;
    hControl = CreateWindowA(type.c_str(), (data == "") ? NULL : data.c_str(), style,
        x, y, cx, cy, parent, (HMENU)id, hInst, NULL);
}

Control::Control(int x, int y, int cx, int cy, int id, WNDPROC proc)
{
    ID = id;
    hControl = CreateDialogA(hInst, MAKEINTRESOURCEA(id), hWnd, proc);
    MoveWindow(hControl, x, y, cx, cy, TRUE);
    ShowWindow(hControl, 1);
}
