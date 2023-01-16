#pragma once
#include<vector>

namespace App
{
	enum class ObjectTag : unsigned char
	{
		Player,
		PlayerShot,
		Enemy,
		EnemyShot,
		Boss,
		BossShot,
	};


	constexpr static ObjectTag ObjectTagAll[] =
	{
		ObjectTag::Player,
		ObjectTag::PlayerShot,
		ObjectTag::Enemy,
		ObjectTag::EnemyShot,
		ObjectTag::Boss,
		ObjectTag::BossShot,
	};
}