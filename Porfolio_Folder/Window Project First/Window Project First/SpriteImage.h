#pragma once

#include<Windows.h>
#include <string>
#include <vector>

class SpriteImage
{
public:
	void Draw(HDC hDC, int x, int y, int x2, int y2, int cx, int cy);
	void SetTransparent(int r, int g, int b);
	void PushSlice(int x, int y, int width, int height);
	void DrawSlice(HDC hDC, int x, int y, int index);
	size_t GetSliceCnt() const { return slice.size(); }
public:
	RECT GetSliceIndex(int index) {
		return slice[index];
	}
public:
	SpriteImage(HDC hDC, std::string Path);
	~SpriteImage();
private:
	std::vector<RECT> slice;
	UINT transparent;
	HBITMAP original, old;
	HDC MemoryDC;
};

