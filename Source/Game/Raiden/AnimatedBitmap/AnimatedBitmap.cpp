#include <StdAfx.h>
#include "AnimatedBitmap.h"
#include "../AnimationSetting/AnimationSetting.h"

namespace Raiden
{
	void AnimatedBitmap::SetTopLeft(int left, int top)
	{
		sprite.SetTopLeft(left, top);
	}

	void AnimatedBitmap::SetCenter(int center_x, int center_y)
	{
		sprite.SetTopLeft(center_x - sprite.GetWidth() / 2, center_y - sprite.GetHeight() / 2);
	}

	void AnimatedBitmap::AddAnimation(AnimationSetting &&setting)
	{
		settings.push_back(std::move(setting));
	}

	void AnimatedBitmap::ChangeAnimation(std::size_t animation_index)
	{
		sprite.LoadBitmapByString(settings[animation_index].frames);
		sprite.SetAnimation(settings[animation_index].delay, settings[animation_index].once);
		sprite.ToggleAnimation();
	}

	void AnimatedBitmap::ClearAnimation()
	{
		sprite.LoadEmptyBitmap(0, 0);
		settings.clear();
	}

	void AnimatedBitmap::Show()
	{
		sprite.ShowBitmap();
	}
}
