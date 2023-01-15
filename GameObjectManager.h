#pragma once
#include<DxLib.h>
#include<vector>
#include<unordered_map>
#include"GameObject.h"
#include"ObjectTag.h"
#include"Math.h"

namespace App
{
	class GameObjectManager final
	{
	public:
		static void Init();
		static void Entry(GameObject* newObj);
		static void Release(GameObject* releaseObj);
		static void ReleaseAllObj();
		static void Update(float deltaTime);
		static void Draw();
		static void Finalize();

	private:
		GameObjectManager();
		~GameObjectManager();
		static GameObjectManager* mpInstance;
		std::vector<GameObject*>  mPendingObjects;
		std::vector<GameObject*>  mObjects;
	};
}