#pragma once
#include "../../../Library/gameutil.h"
#include "../Control/Control.h"
#include "../Data/PlayerData.h"
#include "../GameObjectPool/GameObjectPool.h"
#include "../Bullet/Bullet.h"
#include "../Collidable/Collidable.h"
#include <set>
#include <ctime>

namespace Raiden
{
	class Player : public Collidable
	{
	public:
		void Init(PlayerData&& player_data, std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet);
		void Update(const Control &control);
		void Show();
		int GetScore() const;
		int GetHighScore() const;
		int GetLifeCount() const;
		int GetBombCount() const;
		void Damage();
		void Upgrage();
		void IncreaseScore(int amount);
		void fdajklgasjklsra();
		CPoint GetTopLeft();
		bool IsInvincible();
		bool IsAttacking() const;
	private:
		void UpdateByKeyboard(const std::set<Key> &keys);
		void UpdateByMouse(CPoint point);
		const int MOVE_STEP = 10;
		game_framework::CMovingBitmap sprite;
		int sprite_index = 5;
		int score = 0;
		int high_score = 0;
		int life_count = 3;
		int bomb_count = 3;
		int level = 1;
		std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>> bullets;
		std::clock_t fire_cooldown_clock;
		bool invincible = false;
		std::clock_t invincible_time;
		bool attacking = false;
		int last_sprite_index = 11;
	};
}
