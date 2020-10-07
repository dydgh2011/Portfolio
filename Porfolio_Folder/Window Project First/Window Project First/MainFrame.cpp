#include "MainFrame.h"
#include "ControlCenter.h"
#include "SpriteCenter.h"
#include "Timer.h"
#include "AnimationCenter.h"
#include "ObjectCenter.h"

#include "questionbox.h"
#include "Player.h"
#include "stage_one.h"
#include "Monster1.h"
#include "ground.h"

extern SpriteCenter SC;
extern AnimationCenter AC;
extern Timer Time;
extern ObjectCenter OC;

bool MainFrame::Initialize()
{
    SC.Initialize();

    FrameChecker = 0;

    int ImageCount = GetPrivateProfileIntA("ImageSetting", "Count", -1, "./resources/src/Sprites.ini");

    for (int i = 0; i < ImageCount; ++i) {
        // _atoi64();
        string path = "./resources/bit/";
        char temp[64];
        char fname[64];
        char size[256];
        int r, g, b;
        _itoa_s(i, temp, 10);
        GetPrivateProfileStringA("ImageSetting", temp, "", fname, 64, "./resources/src/Sprites.ini");
        SC.PushSprite(path + fname);
        char index[64];
        int cnt = GetPrivateProfileIntA(temp, "Count", 0, "./resources/src/Sprites.ini");
        for (int j = 0; j < cnt; ++j) {
            _itoa_s(j, index, 10);
            GetPrivateProfileStringA(temp, index, "", size, 256, "./resources/src/Sprites.ini");
            string sizes = size;
            int finder = sizes.find(",", 0);
            string x = sizes.substr(0, sizes.find(",", 0));
            finder = sizes.find(",", 0) + 1;
            string y = sizes.substr(finder, sizes.find(",", 1));
            finder = sizes.find(",", finder) + 1;
            string w = sizes.substr(finder, sizes.find(",", 2));
            finder = sizes.find(",", finder) + 1;
            string h = sizes.substr(finder, sizes.find(",", 3));
            int ix, iy, iw, ih;
            ix = _atoi64(x.c_str());
            iy = _atoi64(y.c_str());
            iw = _atoi64(w.c_str());
            ih = _atoi64(h.c_str());
            SC[i]->PushSlice(ix, iy, iw, ih);
        }
        r = GetPrivateProfileIntA(temp, "r", 0, "./resources/src/Sprites.ini");
        g = GetPrivateProfileIntA(temp, "g", 0, "./resources/src/Sprites.ini");
        b = GetPrivateProfileIntA(temp, "b", 0, "./resources/src/Sprites.ini");
        SC[i]->SetTransparent(r, g, b);
    }

    AC.Push("walking", 1, 0, 7);
    AC.Push("char_down", 0, 0, 3);
    AC.Push("char_up", 0, 4, 7);
    AC.Push("char_left", 0, 8, 11);
    AC.Push("char_right", 0, 12, 15);
    AC.Push("mario_right", 2, 1, 3);
    AC.Push("mario_left", 2, 5, 7);
    AC.Push("mario_right_stand", 2, 0, 0);
    AC.Push("mario_left_stand", 2, 4, 4);
    AC.Push("mario_block_used_quesiton_box", 3, 0, 0);
    AC.Push("mario_block_normal", 3, 1, 1);
    AC.Push("mario_block_question_box", 3, 2, 2);
    AC.Push("mario_block_ground", 3, 3, 3);
    AC.Push("mario_block_unbrokable", 3, 4, 4);
    AC.Push("goomba_walking", 4, 0, 1);
    AC.Push("goomba_die", 4, 2, 2);
    AC.Push("flag", 5, 0, 0);
    Object* stage1s = new stage_one();
    OC.PushObject(stage1s);

    return true;
}

void MainFrame::Render()
{
    FrameChecker += Time.Delta();
    if (FrameChecker >= 0.06) {
        FrameChecker = 0;
        Rectangle(SC.DrawDC, -1, -1, 1200, 1200);
        OC.Render();
        BitBlt(SC.hDC, 0, 0, 1200, 1200, SC.DrawDC, 0, 0, SRCCOPY);
    }

}

void MainFrame::Progress()
{
    OC.Progress();
}

MainFrame::~MainFrame()
{
}
