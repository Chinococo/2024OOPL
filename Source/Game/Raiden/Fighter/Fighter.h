#pragma once
#include "../../../Library/gameutil.h"
#include "../Player/Player.h"
#include "../Collidable/Collidable.h"
#include "../Data/FighterData.h"
#include <vector>
#include <ctime>

namespace Raiden
{
	class Fighter : public Collidable
	{
	public:
		void Init(FighterData &&fighter_data, std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>> bullets);
		void Update(const Player &player, int scrolled_distance);
		void Show(bool debug);
		void Destroy();
		bool IsAlive() const;
		bool IsAttacking() const;
		int GetLeft();
		int GetTop();

	private:
		void Move(int left, int top);
		game_framework::CMovingBitmap sprite;
		std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>> bullets;
		int health = 10;
		bool alive = true;
		std::vector<CPoint> positions;
		std::size_t position_index = 0;
		std::clock_t start_move_time;
		std::clock_t move_clock;
		std::clock_t move_interval_milli = 1000;
		std::clock_t shoot_clock= std::clock();
		int bullet_speed;
		int bullet_type;
		int bullet_angle;
		int appear_distance = 0;
		std::vector<bool> attack_positions;
		const double M_PI = 3.14159265358979323846;
		int last_distance = 0;
		bool IsAppear = false;
		int offset_x = (-3 + (std::rand() % 6));

	};
}
