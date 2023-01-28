#include"GameManager.h"
#include"AssetManager.h"
#include"GameObjectManager.h"
#include"Collision.h"
#include"Camera.h"
#include"Title.h"
#include"OperationMethod.h"
#include"GamePlay.h"
#include"Result.h"
#include"PlayerShot.h"
#pragma warning(disable:4996)

namespace App
{
    GameManager::GameManager()
    {
    }

    GameManager::~GameManager()
    {
        delete player;
        delete gameState;
        delete freq;
        delete start;
        delete end;

        player    = nullptr;
        gameState = nullptr;
        freq      = nullptr;
        start     = nullptr;
        end       = nullptr;
    }

    void GameManager::Init()
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

        player    = new App::Player();
        gameState = new App::Title();

        App::GameObjectManager::Entry(player);

        freq = new LARGE_INTEGER();
        start = new LARGE_INTEGER();
        end = new LARGE_INTEGER();

        nowCount = prevCount = GetNowHiPerformanceCount();

        QueryPerformanceFrequency(freq);
        QueryPerformanceCounter(start);
    }
    void GameManager::Loop()
    {
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            float deltaTime;
            nowCount = GetNowHiPerformanceCount();
            deltaTime = (nowCount - prevCount) / 1000000.0f;

            QueryPerformanceCounter(end);
            double time = static_cast<double>(end->QuadPart - start->QuadPart) * 1.0 / freq->QuadPart;

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
    }
    void GameManager::Finalize()
    {
        App::GameObjectManager::Finalize();
        App::AssetManager::Finalize();

        DxLib_End();
    }
}