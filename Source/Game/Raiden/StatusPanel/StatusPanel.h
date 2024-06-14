#pragma once
#include "../TextGraphics/TextGraphics.h"
#include <map>

namespace Raiden {
	class StatusPanel {
	public:
		void Init();
		void SetHealth(int);
		void SetScore(int);
		void SetBombCount(int);
		void Show(TextGraphics&);

	private:
		int health;
		int score;
		int bomb_count;
		CPoint health_pos;
		CPoint score_pos;
		CPoint bomb_count_pos;
		std::size_t health_text_id;
		std::size_t score_text_id;
		std::size_t score_count_id;
		std::size_t bomb_count_text_id;
		game_framework::CMovingBitmap status_image;
	};
}
