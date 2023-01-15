#include"GameObject.h"
#include"AssetManager.h"

namespace App
{
	GameObject::GameObject(ObjectTag tag)
		: mTag(tag)
		, mPos()
		, mDir()
		, mModelHandle(-1)
		, mAlive(true)
	{
	}
	GameObject::~GameObject()
	{
		if (mModelHandle != -1)
		{
			AssetManager::ReleaseMesh(mModelHandle);
			mModelHandle = -1;
		}
	}
	void GameObject::Draw()
	{
	}
}