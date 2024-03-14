#pragma once
#include "../../../Library/gameutil.h"
#include "../AnimationSetting/AnimationSetting.h"
#include <vector>

namespace Raiden
{
	class AnimatedBitmap
	{
	public:
		void SetTopLeft(int left, int top);
		void SetCenter(int center_x, int center_y);
		void AddAnimation(AnimationSetting &&setting);
		void ChangeAnimation(std::size_t animation_index);
		void ClearAnimation();
		void Show();

	private:
		game_framework::CMovingBitmap sprite;
		std::vector<AnimationSetting> settings;
	};
}
