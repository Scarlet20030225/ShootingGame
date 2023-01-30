#include"GameManager.h"
#include"AssetManager.h"
#include"GameObjectManager.h"
#include"Collision.h"
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
        // DxLib������
        ChangeWindowMode(TRUE);
        DxLib_Init();
        SetGraphMode(1920, 1080, 32);
        //SetBackgroundColor(255, 255, 255);

        App::GameObjectManager::Init();
        App::AssetManager::Init();

        player    = new App::Player();
        gameState = new App::Title();
        camera    = new App::Camera();
        freq      = new LARGE_INTEGER();
        start     = new LARGE_INTEGER();
        end       = new LARGE_INTEGER();

        App::GameObjectManager::Entry(player);

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

            //��ʍX�V����
            ClearDrawScreen();

            // �o�ߎ��ԕ`��(��ŏ���)
            char buf[256];
            DrawString(0, 0, buf, GetColor(255, 0, 0));
            sprintf(buf, "�o�ߎ��ԁF%f�b\n", time);

            //gameState->Draw();
            App::GameObjectManager::Draw();

            ScreenFlip();

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