#include "DxLib.h"

#pragma warning(disable:4996)

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib‰Šú‰»
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);

    if (DxLib_Init() == -1)
    {
        return -1;
    }



    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //‰æ–ÊXVˆ—
        ClearDrawScreen();
        ScreenFlip();
    }


    DxLib_End();
    return 0;
}