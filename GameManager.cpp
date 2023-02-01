#include"GameManager.h"
#include"AssetManager.h"
#include"GameObjectManager.h"
#include"Collision.h"
#include"Title.h"
#include"OperationMethod.h"
#include"GamePlay.h"
#include"Result.h"
#include"PlayerShot.h"
#include <chrono>
#include <thread>
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

        player    = nullptr;
        gameState = nullptr;
    }

    void GameManager::Init()
    {
        // DxLib‰Šú‰»
        ChangeWindowMode(TRUE);
        DxLib_Init();
        SetGraphMode(1920, 1080, 32);
        //SetBackgroundColor(255, 255, 255);

        App::GameObjectManager::Init();
        App::AssetManager::Init();

        player    = new App::Player();
        gameState = new App::Title();
        camera    = new App::Camera();

        App::GameObjectManager::Entry(player);

        fps = 60;
        deltaTime = 1000 / fps;
    }

    void GameManager::Loop()
    {
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            auto start = std::chrono::system_clock::now();

            //gameState->Update(deltaTime);
            App::GameObjectManager::Update(deltaTime);

            //‰æ–ÊXVˆ—
            ClearDrawScreen();

            //gameState->Draw();
            App::GameObjectManager::Draw();

            ScreenFlip();

            auto end = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

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

        DxLib_End();
    }
}