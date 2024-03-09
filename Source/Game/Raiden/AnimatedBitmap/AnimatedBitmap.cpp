#include <StdAfx.h>
#include <exception>
#include "AnimatedBitmap.hpp"

namespace Raiden
{
	void AnimatedBitmap::AddAnimation(Setting setting)
	{
		settings.push_back(setting);
	}

	void AnimatedBitmap::SwitchAnimation(std::size_t index)
	{
		if (index >= settings.size())
			throw std::invalid_argument("Invalid animation index");

		sprite.LoadBitmapByString(settings[index].frames);
		sprite.SetAnimation(settings[index].delay, settings[index].once);
		sprite.ToggleAnimation();
	}

	void AnimatedBitmap::Update()
	{

	}

	void AnimatedBitmap::Show()
	{
		sprite.ShowBitmap();
	}
}
