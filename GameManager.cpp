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
        // DxLib������
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

        // �t���[����60fps��
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
            // �����J�n����������
            auto start = std::chrono::system_clock::now();

            // Update����
            //gameState->Update(deltaTime);
            App::GameObjectManager::Update(deltaTime);
            gamePlaySceen->Update(deltaTime);

            //��ʍX�V����
            ClearDrawScreen();

            // �`�揈��
            //gameState->Draw();
            collisionDetection->Detection();
            gamePlaySceen->Draw();
            App::GameObjectManager::Draw();

            // �`����m��
            ScreenFlip();

            // 1�t���[���ɂ����鎞�Ԃ��v�Z
            auto end = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            // 1�t���[���ɂ����������Ԃ��w��̎��Ԉȉ��ł���Αҋ@����
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

        // ���C�u�����I������
        DxLib_End();
    }
}