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
			std::vector<std::string> paths;
			int delay;
			bool once;
		};

		void SetCenter(int left, int top);
		void AddAnimation(Setting setting);
		void SwitchAnimation(std::size_t index);
		void Show();

	private:
		game_framework::CMovingBitmap sprite;
		std::vector<Setting> settings;
	};
}
