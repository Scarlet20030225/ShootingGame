#include<windows.h>
#include"DxLib.h"
#include"AssetManager.h"
#include"GameObject.h"
#include"GameObjectManager.h"
#include"Collision.h"
#include"Player.h"
#include"PlayerShot.h"
#pragma warning(disable:4996)

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib初期化
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);
    //SetBackgroundColor(255, 255, 255);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // カメラ
    SetCameraNearFar(1.0f, 2000.0f);
    SetCameraPositionAndTarget_UpVecY(VGet(960.0f, 540.0f, -1000.0f), VGet(960.0f, 540.0f, 0.0f));

    // ライト
    SetLightDirection(VGet(0.0f, 0.0f, 1.0f));
    SetLightPosition(VGet(960.0f, 540.0f, -1000.0f));

    App::GameObjectManager::Init();
    App::AssetManager::Init();

    App::Player* player = new App::Player;
    App::GameObjectManager::Entry(player);

    LONGLONG nowCount, prevCount;                      // マイクロ秒(100万分の1秒単位で時刻取得)
    nowCount = prevCount = GetNowHiPerformanceCount();
    float fixedDeltaTime = 1.0f / 60.0f;               // 60分の1秒 = 0.01666...秒
    float waitFrameTime = 15500;                       // 16000マイクロ秒 = 16ミリ秒 = 0.016秒


    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start);

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        float deltaTime;
        nowCount = GetNowHiPerformanceCount();
        deltaTime = (nowCount - prevCount) / 1000000.0f;

        App::GameObjectManager::Update(deltaTime);

        //画面更新処理
        ClearDrawScreen();

        char buf[256];
        //sprintf(buf, "deltaTime = %f, FPS : %f", deltaTime, 1.0f / deltaTime);
        DrawString(0, 0, buf, GetColor(255, 255, 255));

        App::GameObjectManager::Draw();

        ScreenFlip();

        while (GetNowHiPerformanceCount() - nowCount < waitFrameTime)
        {
            ;
        }
        prevCount = nowCount;
        QueryPerformanceCounter(&end);

        double time = static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
        sprintf(buf, "経過時間：%lf[ms]\n", time);
    }
    App::GameObjectManager::Finalize();
    App::AssetManager::Finalize();

    DxLib_End();
    return 0;
}