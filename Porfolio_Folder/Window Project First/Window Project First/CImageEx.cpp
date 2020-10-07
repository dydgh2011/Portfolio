#include "CImageEx.h"

void CImageEx::Draw(int x, int y)
{
	BitBlt(x - width / 2, y - height / 2, width, height, 0, 0);
}

CImageEx::CImageEx(HWND hWnd, HDC hDC, std::string Path, int width, int height)
	:CBitimage(hWnd,hDC,Path),width(width),height(height)
{}
