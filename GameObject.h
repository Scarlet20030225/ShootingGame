#pragma once
#include"DxLib.h"
#include"Math.h"
#include"ObjectTag.h"

namespace App
{
	class GameObject
	{
	public:
		GameObject(ObjectTag tag);
		virtual ~GameObject();

		const VECTOR& GetPos() const { return mPos; }
		void SetPos(const VECTOR set) { mPos = set; }

		const VECTOR& GetDir() const { return mDir; }
		void SetDir(const VECTOR dir) { mDir = dir; }

		bool GetAlive() { return mAlive; }
		void SetAlive(bool alive) { mAlive = alive; }

		ObjectTag GetTag() { return mTag; }

		virtual void Update(float deltaTime) = 0;
		virtual void Draw();

	protected:
		ObjectTag mTag;
		VECTOR mPos;
		VECTOR mDir;  
		int mModelHandle;
		bool mAlive;
	};
}