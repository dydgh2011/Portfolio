#include "SpriteImage.h"

#pragma comment(lib, "msimg32.lib")

void SpriteImage::Draw(HDC hDC, int x, int y, int x2, int y2, int cx, int cy)
{
	TransparentBlt(hDC, x, y, cx, cy, MemoryDC, x2, y2, cx, cy, transparent);
}

void SpriteImage::SetTransparent(int r, int g, int b)
{
	transparent = RGB(r, g, b);
}

void SpriteImage::PushSlice(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = x;
	rc.top = y;
	rc.right = width;
	rc.bottom = height;
	slice.push_back(rc);
}

void SpriteImage::DrawSlice(HDC hDC, int x, int y, int index)
{
	Draw(hDC, x, y, slice[index].left, slice[index].top, slice[index].right, slice[index].bottom);
}

SpriteImage::SpriteImage(HDC hDC, std::string Path)
	:transparent(0)
{
	MemoryDC = CreateCompatibleDC(hDC);
	original = (HBITMAP)LoadImageA(
		NULL,
		Path.c_str(),
		IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE);
	old = (HBITMAP)SelectObject(MemoryDC, original);
}

SpriteImage::~SpriteImage()
{
	SelectObject(MemoryDC, old);
	DeleteDC(MemoryDC);
	DeleteObject(original);
	DeleteObject(old);
}
