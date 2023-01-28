#include"GameManager.h"
#include"AssetManager.h"
#include"GameObject.h"
#include"GameObjectManager.h"
#include"Collision.h"
#include"Camera.h"
#include"Title.h"
#include"OperationMethod.h"
#include"GamePlay.h"
#include"Result.h"
#include"Player.h"
#include"PlayerShot.h"
#pragma warning(disable:4996)

namespace App
{
    GameManager::GameManager()
    {
    }

    GameManager::~GameManager()
    {
    }

    void GameManager::Game()
    {
        // DxLib初期化
        ChangeWindowMode(TRUE);
        DxLib_Init();
        SetGraphMode(1920, 1080, 32);
        //SetBackgroundColor(255, 255, 255);

        // カメラ
        SetCameraNearFar(1.0f, 2000.0f);
        SetCameraPositionAndTarget_UpVecY(VGet(960.0f, 540.0f, -1000.0f), VGet(960.0f, 540.0f, 0.0f));

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

        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            float deltaTime;
            nowCount = GetNowHiPerformanceCount();
            deltaTime = (nowCount - prevCount) / 1000000.0f;

            QueryPerformanceCounter(&end);
            double time = static_cast<double>(end.QuadPart - start.QuadPart) * 1.0 / freq.QuadPart;

            //gameState->Update(deltaTime);
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

        App::GameObjectManager::Finalize();
        App::AssetManager::Finalize();

        DxLib_End();
    }
}