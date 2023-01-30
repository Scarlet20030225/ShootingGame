#include"DxLib.h"
#include"Camera.h"

App::Camera::Camera()
{
    SetCameraNearFar(1.0f, 2000.0f);
    SetCameraPositionAndTarget_UpVecY(VGet(960.0f, 540.0f, -1000.0f), VGet(960.0f, 540.0f, 0.0f));

    // ���C�g(�g�����ǂ����͍Ō�Ɍ��߂�)
    /*SetLightDirection(VGet(0.0f, 0.0f, 1.0f));
    SetLightPosition(VGet(960.0f, 540.0f, -1000.0f));*/
}

App::Camera::~Camera()
{
}