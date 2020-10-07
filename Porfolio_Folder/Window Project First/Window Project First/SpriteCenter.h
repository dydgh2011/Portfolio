#pragma once

#include "SpriteImage.h"
#include <vector>
#include <string>

class SpriteCenter
{
private:
	std::vector<SpriteImage*> sprites;
public:
	SpriteImage* operator[](int index) {
		return sprites[index];
	}
public:
	void PushSprite(std::string path) {
		sprites.push_back(new SpriteImage(hDC, path));
	}
	void Initialize();
public:
	static HWND hWnd;
	static HDC hDC;
	static HDC DrawDC;
	HBITMAP Buff, Old;
public:
	SpriteCenter();
	~SpriteCenter();
};

