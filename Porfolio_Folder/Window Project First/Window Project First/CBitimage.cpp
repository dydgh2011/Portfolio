#include "CBitimage.h"

void CBitimage::BitBlt(int x, int y, int cx, int cy, int x1, int y1)
{
	::BitBlt(hDC, x, y, cx, cy, MemoryDC, x1, y1, SRCCOPY);
}

CBitimage::CBitimage(HWND hWnd, HDC hDC, std::string Path)
{
	this->hWnd = hWnd;
	this->hDC = hDC;
	MemoryDC = CreateCompatibleDC(this->hDC);
	original = (HBITMAP)LoadImageA(
		NULL,
		Path.c_str(),
		IMAGE_BITMAP,
		0,0, LR_LOADFROMFILE);
	old = (HBITMAP)SelectObject(MemoryDC, original);
}

CBitimage::~CBitimage()
{
	SelectObject(MemoryDC, old);
	DeleteDC(MemoryDC);
	DeleteObject(original);
	DeleteObject(old);
}
