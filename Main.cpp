#include<windows.h>
#include"DxLib.h"
#include"AssetManager.h"
#include"GameObject.h"
#include"GameObjectManager.h"
#include"Collision.h"
#include"Camera.h"
#include"Player.h"
#include"PlayerShot.h"
#include"GameState.h"
#include"Title.h"
#pragma warning(disable:4996)

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    //------------------------------------------------------------------------------------------------------------
    // 初期化
    //------------------------------------------------------------------------------------------------------------
    // DxLib初期化
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);
    //SetBackgroundColor(255, 255, 255);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // カメラ
    App::Camera();

    // ライト(使うかどうかは最後に決める)
    /*SetLightDirection(VGet(0.0f, 0.0f, 1.0f));
    SetLightPosition(VGet(960.0f, 540.0f, -1000.0f));*/

    App::GameObjectManager::Init();
    App::AssetManager::Init();

    App::Player* player = new App::Player;
    App::GameObjectManager::Entry(player);

    App::GameState* gameState = new App::Title;

    LONGLONG nowCount, prevCount;
    nowCount = prevCount = GetNowHiPerformanceCount();
    float fixedDeltaTime = 1.0f / 60.0f;
    float waitFrameTime = 15500;

    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start);

    //-------------------------------------------------------------------------------------------------------------------------------
    // ループ
    //-------------------------------------------------------------------------------------------------------------------------------
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        float deltaTime;
        nowCount = GetNowHiPerformanceCount();
        deltaTime = (nowCount - prevCount) / 1000000.0f;

        QueryPerformanceCounter(&end);
        double time = static_cast<double>(end.QuadPart - start.QuadPart) * 1.0 / freq.QuadPart;

        //gameState->Update();
        App::GameObjectManager::Update(deltaTime);

        //画面更新処理
        ClearDrawScreen();

        char buf[256];
        sprintf(buf, "経過時間：%f秒\n", time);
        DrawString(0, 0, buf, GetColor(255, 0, 0));

        //gameState->Draw();
        App::GameObjectManager::Draw();

        ScreenFlip();

        while (GetNowHiPerformanceCount() - nowCount < waitFrameTime)
        {
            ;
        }
        prevCount = nowCount;
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    // 終了処理
    //----------------------------------------------------------------------------------------------------------------------------------
    App::GameObjectManager::Finalize();
    App::AssetManager::Finalize();

    DxLib_End();
    return 0;
}