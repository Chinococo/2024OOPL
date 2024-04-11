#include "stdafx.h"
#include "Player.h"
#include "../../config.h"
#include <set>
#include <vector>
#include <string>
#include <tuple>

namespace Raiden
{
	void Player::Init(PlayerData && player_data, std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet)
	{
		int color_mask_red = std::get<0>(player_data.color_mask);
		int color_mask_green = std::get<1>(player_data.color_mask);
		int color_mask_blue = std::get<2>(player_data.color_mask);
		bullets = bullet;
		sprite.LoadBitmapByString(player_data.sprites, RGB(color_mask_red, color_mask_green, color_mask_blue));
		sprite.SetFrameIndexOfBitmap(sprite_index);
		sprite.SetTopLeft(player_data.init_position.x, player_data.init_position.y);
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
		sprite.SetFrameIndexOfBitmap(sprite_index);
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

		if ((keys.count(Key::RIGHT) - keys.count(Key::LEFT)) != 0) 
			sprite_index +=  (keys.count(Key::RIGHT) - keys.count(Key::LEFT));

		else 
			if (sprite_index < 5)
				sprite_index += 1;
			else if (sprite_index > 5) 
				sprite_index -= 1;
			
		sprite_index = min(10, max(0, sprite_index));
		left = max(0, left);
		top = max(0, top);

		const double OFFSET = 1.5;
		left = min(SIZE_X - static_cast<int>(sprite.GetWidth() * OFFSET), left);
		top = min(SIZE_Y - static_cast<int>(sprite.GetHeight() * OFFSET), top);

		sprite.SetTopLeft(left, top);

		if (keys.count(Key::FIRE)) {
			int index = bullets->AddElement();
			auto test = *bullets;
			test[index]->Init();
			test[index]->SetTopLeft({ left,top });
			test[index]->ApplyForce({ 0,-3 });
			

		}
	}

	void Player::UpdateByMouse(CPoint point)
	{
		sprite.SetTopLeft(point.x - sprite.GetWidth() / 2, point.y - sprite.GetWidth() / 2);

		// TODO
	}
}
