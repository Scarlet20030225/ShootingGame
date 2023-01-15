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

    SetCameraNearFar(1.0f, 2000.0f);
    SetCameraPositionAndTarget_UpVecY(VGet(0, 580, -200), VGet(0.0f, 80.0f, 0.0f));


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //‰æ–ÊXVˆ—
        ClearDrawScreen();
        ScreenFlip();
    }


    DxLib_End();
    return 0;
}