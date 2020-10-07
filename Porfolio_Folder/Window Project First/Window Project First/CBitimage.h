#pragma once
#include<Windows.h>
#include<string>
class CBitimage
{
private:
	HBITMAP original, old;
	HWND hWnd;
	HDC hDC;
	HDC MemoryDC;
public:
	void BitBlt(int x, int y, int cx, int cy, int x1 = 0, int y1 = 0);
public:
	CBitimage(HWND hWnd, HDC hDC, std::string Path); // ./Bitmap1.bmp
	virtual ~CBitimage();
};

