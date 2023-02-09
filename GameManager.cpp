#include<chrono>
#include<thread>

#include"GameManager.h"
#include"AssetManager.h"
#include"GameObjectManager.h"
#include"Title.h"
#include"OperationMethod.h"
#include"GamePlay.h"
#include"Result.h"

#pragma warning(disable:4996)

namespace App
{
    GameManager::GameManager()
    {
        // DxLib初期化
        ChangeWindowMode(TRUE);
        DxLib_Init();
        SetGraphMode(screenSizeX, screenSizeY, colorBitDepth);
        //SetBackgroundColor(255, 255, 255);

        App::GameObjectManager::Init();
        App::AssetManager::Init();

        player = new App::Player();
        playerShot = new App::PlayerShot(player);
        boss = new App::Boss();
        bossShot = new App::BossShot(boss);
        gameState = new App::Title();
        camera = new App::Camera();
        collisionDetection = new App::CollisionDetection();
        gamePlaySceen = new App::GamePlayScreen();

        App::GameObjectManager::Entry(player);
        App::GameObjectManager::Entry(boss);

        // フレームを60fpsに
        fps = 60;
        deltaTime = 1000 / fps;
    }

    GameManager::~GameManager()
    {
        delete player;
        delete playerShot;
        delete boss;
        delete bossShot;
        delete gameState;
        delete collisionDetection;

        player             = nullptr;
        playerShot         = nullptr;
        boss               = nullptr;
        bossShot           = nullptr;
        gameState          = nullptr;
        collisionDetection = nullptr;
    }

    void GameManager::Loop()
    {
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            // 処理開始時刻を所得
            auto start = std::chrono::system_clock::now();

            // Update処理
            //gameState->Update(deltaTime);
            App::GameObjectManager::Update(deltaTime);
            gamePlaySceen->Update(deltaTime);

            //画面更新処理
            ClearDrawScreen();

            // 描画処理
            //gameState->Draw();
            collisionDetection->Detection();
            gamePlaySceen->Draw();
            App::GameObjectManager::Draw();

            // 描画を確定
            ScreenFlip();

            // 1フレームにかかる時間を計算
            auto end = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            // 1フレームにかかった時間が指定の時間以下であれば待機する
            if (elapsed.count() < deltaTime)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(deltaTime - elapsed.count()));
            }
        }
    }

    void GameManager::Finalize()
    {
        App::GameObjectManager::Finalize();
        App::AssetManager::Finalize();

        // ライブラリ終了処理
        DxLib_End();
    }
}