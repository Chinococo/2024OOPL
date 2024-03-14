#pragma once
#include "../../../Library/gameutil.h"
#include "../Key/Key.h"
#include <set>

namespace Raiden
{
	class Player
	{
	public:
		void Init();
		void Update(const std::set<Key> &keys);
		void Show();
		int GetScore() const;
		int GetHighScore() const;
		int GetLifeCount() const;
		int GetBombCount() const;

	private:
		const int MOVE_STEP = 10;
		game_framework::CMovingBitmap sprite;
		std::size_t sprite_index = 5;
		int score = 0;
		int high_score = 0;
		int life_count = 3;
		int bomb_count = 3;
	};
}
