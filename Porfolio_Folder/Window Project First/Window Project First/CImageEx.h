#pragma once
#include "CBitimage.h"
class CImageEx :
    public CBitimage
{
private:
    int width, height;
public:
    void Draw(int x, int y);
public:
    CImageEx(HWND hWnd, HDC hDC, std::string Path, int width, int height);
};

