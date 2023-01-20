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
    // DxLibèâä˙âª
    ChangeWindowMode(TRUE);
    SetGraphMode(1920, 1080, 32);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    SetCameraNearFar(1.0f, 2000.0f);
    SetCameraPositionAndTarget_UpVecY(VGet(0, 0, -1000), VGet(0.0f, 0.0f, 0.0f));

    App::GameObjectManager::Init();
    App::AssetManager::Init();

    App::Player* player = new App::Player;
    App::GameObjectManager::Entry(player);

    int nowTime = GetNowCount();
    int prevTime = nowTime;
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        nowTime = GetNowCount();
        float deltaTime = (nowTime - prevTime) / 1000.0f;

        char buf[256];
        sprintf(buf, "deltaTime[%5.4f]", deltaTime);

        App::GameObjectManager::Update(deltaTime);

        //âÊñ çXêVèàóù
        ClearDrawScreen();
        DrawString(100, 100, buf, GetColor(255, 255, 255));

        App::GameObjectManager::Draw();

        ScreenFlip();

        prevTime = nowTime;
    }
    App::GameObjectManager::Finalize();
    App::AssetManager::Finalize();

    DxLib_End();
    return 0;
}