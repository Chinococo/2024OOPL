#include "stdafx.h"
#include "Player.h"
#include <set>
#include <vector>
#include <string>

namespace Raiden
{
	void Player::Init()
	{
		std::vector<std::string> paths;

		for (int i = 0; i <= 10; i++)
			paths.push_back("Resources/Player/Player" + std::to_string(i) + ".bmp");

		sprite.LoadBitmapByString(paths, RGB(0, 0, 255));
		sprite.SetFrameIndexOfBitmap(sprite_index);
		sprite.SetTopLeft(0, 0);
	}

	void Player::Update(const Control &control)
	{
		if (control.mode == ControlMode::KEYBOARD)
			UpdateByKeyboard(control.keys);
		else
			UpdateByMouse(control.point);
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

	void Player::UpdateByKeyboard(const std::set<Key> &keys)
	{
		int left = sprite.GetLeft() + (keys.count(Key::RIGHT) - keys.count(Key::LEFT)) * MOVE_STEP;
		int top = sprite.GetTop() + (keys.count(Key::DOWN) - keys.count(Key::UP)) * MOVE_STEP;

		sprite.SetTopLeft(left, top);

		// TODO
	}

	void Player::UpdateByMouse(CPoint point)
	{
		sprite.SetTopLeft(point.x - sprite.GetWidth() / 2, point.y - sprite.GetWidth() / 2);

		// TODO
	}
}
