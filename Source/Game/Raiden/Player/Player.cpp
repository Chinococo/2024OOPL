#include <StdAfx.h>
#include "Player.hpp"

namespace Raiden
{
	void Player::Init()
	{
		sprite.AddAnimation({ {"Resources/TestSprite/TestSpriteRed.bmp", "Resources/TestSprite/TestSpriteYellow.bmp"}, 300, false });
		sprite.AddAnimation({ {"Resources/TestSprite/TestSpriteLime.bmp", "Resources/TestSprite/TestSpriteBlue.bmp"}, 300, false });
		sprite.AddAnimation({ {"Resources/TestSprite/TestSpritePurple.bmp", "Resources/TestSprite/TestSpriteBrown.bmp"}, 300, false });
		sprite.SwitchAnimation(0);
	}

	void Player::Update()
	{

	}

	void Player::Show()
	{
		sprite.Show();
	}
}
