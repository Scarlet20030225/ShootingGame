#include<windows.h>
#include"GameManager.h"
#pragma warning(disable:4996)

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    //------------------------------------------------------------------------------------------------------------
    // 初期化
    //------------------------------------------------------------------------------------------------------------
    App::GameManager::GameInit;

    //-------------------------------------------------------------------------------------------------------------------------------
    // ループ
    //-------------------------------------------------------------------------------------------------------------------------------
    App::GameManager::GameLoop;

    //----------------------------------------------------------------------------------------------------------------------------------
    // 終了処理
    //----------------------------------------------------------------------------------------------------------------------------------
    App::GameManager::GameEndProcessing;

    return 0;
}