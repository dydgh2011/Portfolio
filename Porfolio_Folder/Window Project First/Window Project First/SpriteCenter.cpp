#include "SpriteCenter.h"

HDC SpriteCenter::DrawDC;

void SpriteCenter::Initialize()
{
	DrawDC = CreateCompatibleDC(hDC);
	Buff = CreateCompatibleBitmap(hDC, 1200, 1200);
	Old = (HBITMAP)SelectObject(DrawDC, Buff);
}

SpriteCenter::SpriteCenter()
{}

SpriteCenter::~SpriteCenter()
{
	for (auto iter = sprites.begin(); iter != sprites.end(); ++iter) {
		delete* iter;
	}
	sprites.clear();

	SelectObject(DrawDC, Old);
	DeleteObject(Buff);
	DeleteDC(DrawDC);
	ReleaseDC(hWnd, hDC);
}
