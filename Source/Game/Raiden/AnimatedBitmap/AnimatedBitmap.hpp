#pragma once
#include <vector>
#include <string>
#include "../../../Library/gameutil.h"

namespace Raiden
{
	class AnimatedBitmap
	{
	public:
		struct Setting
		{
			std::vector<std::string> frames;
			int delay;
			bool once;
		};

		void AddAnimation(Setting setting);
		void SwitchAnimation(std::size_t index);
		void Update();
		void Show();

	private:
		game_framework::CMovingBitmap sprite;
		std::vector<Setting> settings;
	};
}
