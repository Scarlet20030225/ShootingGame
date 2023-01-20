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
    SetCameraPositionAndTarget_UpVecY(VGet(960.0f, 540.0f, -1000.0f), VGet(960.0f, 540.0f, 0.0f));

    App::GameObjectManager::Init();
    App::AssetManager::Init();

    App::Player* player = new App::Player;
    App::GameObjectManager::Entry(player);

    LONGLONG nowCount, prevCount;                      // É}ÉCÉNÉçïb(100ñúï™ÇÃ1ïbíPà Ç≈éûçèéÊìæ)
    nowCount = prevCount = GetNowHiPerformanceCount();
    float fixedDeltaTime = 1.0f / 60.0f;               // 60ï™ÇÃ1ïb = 0.01666...ïb
    float waitFrameTime = 15500;                       // 16000É}ÉCÉNÉçïb = 16É~Éäïb = 0.016ïb

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        float deltaTime;
        nowCount = GetNowHiPerformanceCount();
        deltaTime = (nowCount - prevCount) / 1000000.0f;

        App::GameObjectManager::Update(deltaTime);

        //âÊñ çXêVèàóù
        ClearDrawScreen();

        char buf[256];
        sprintf(buf, "deltaTime = %f, FPS : %f", deltaTime, 1.0f / deltaTime);
        DrawString(0, 0, buf, GetColor(255, 255, 255));

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
    return 0;
}