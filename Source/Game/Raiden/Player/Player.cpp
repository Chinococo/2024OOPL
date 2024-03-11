#include <StdAfx.h>
#include "Player.h"
#include <set>

namespace Raiden
{
	void Player::Init()
	{
		// TODO
		sprite.LoadBitmapByString({ "TODO" });
		sprite.SetTopLeft(0, 0);
	}

	void Player::Update(const std::set<Key> &keys)
	{
		// TODO
	}

	void Player::Show()
	{
		sprite.ShowBitmap();
	}

	int Player::GetScore() const
	{
		return score;
	}

	int Player::GetHighScore() const
	{
		return high_score;
	}

	int Player::GetLifeCount() const
	{
		return life_count;
	}

	int Player::GetBombCount() const
	{
		return bomb_count;
	}
}
