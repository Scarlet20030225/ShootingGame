#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib初期化
    ChangeWindowMode(TRUE);
    SetGraphMode(1440, 900, 16);
    if (DxLib_Init() == -1)
    {
        return -1;
    }
    // ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面更新処理
        ClearDrawScreen();
        ScreenFlip();
    }
    DxLib_End();
    return 0;
}