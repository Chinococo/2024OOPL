#include "stdafx.h"
#include "Player.h"
#include "../../config.h"
#include <set>
#include <vector>
#include <string>
#include <tuple>
#define M_PI 3.1415926
namespace Raiden
{
	void Player::Init(PlayerData && player_data, std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullet)
	{
		this->score = 0;
		this->life_count = 3;
		this->bomb_count = 3;
		this->level = 2;
		int color_mask_red = std::get<0>(player_data.color_mask);
		int color_mask_green = std::get<1>(player_data.color_mask);
		int color_mask_blue = std::get<2>(player_data.color_mask);
		bullets = bullet;
		sprite.LoadBitmapByString(player_data.sprites, RGB(color_mask_red, color_mask_green, color_mask_blue));
		sprite.SetFrameIndexOfBitmap(sprite_index);
		sprite.SetTopLeft(player_data.init_position.x, player_data.init_position.y);
		InitCollisionBox(sprite.GetWidth()/2, sprite.GetHeight()/2);
	}

	void Player::Update(const Control &control)
	{
		attacking = false;
		clock_t now = clock();
		if (invincible&&now - invincible_time > 1 * CLOCKS_PER_SEC) {
			invincible = false;
		}
		if (control.mode == ControlMode::KEYBOARD)
			UpdateByKeyboard(control.keys);
		else
			UpdateByMouse(control.point);
	}

	void Player::Show()
	{
		if (life_count > 0) {
			if (invincible) {
				sprite.SetFrameIndexOfBitmap(sprite_index);
			}
			else {
				sprite.SetFrameIndexOfBitmap(sprite_index);
			}
			
			sprite.ShowBitmap();
			ShowCollisionBox();
		}
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

	void Player::Damage()
	{
		life_count -= 1;
		invincible = true;
		invincible_time = clock();
	}

	void Player::IncreaseScore(int amount) {
		score += amount;
		if (score > high_score) {
			high_score = score;
		}
	}

	void Player::Upgrage()
	{
		level = min((level + 1),5);
	}

	CPoint Player::GetTopLeft()
	{
		return CPoint(this->sprite.GetLeft(), this->sprite.GetTop());
	}

	bool Player::IsInvincible()
	{
		return invincible;
	}

	void Player::UpdateByKeyboard(const std::set<Key> &keys)
	{
		int left = sprite.GetLeft() + (keys.count(Key::RIGHT) - keys.count(Key::LEFT)) * MOVE_STEP;
		int top = sprite.GetTop() + (keys.count(Key::DOWN) - keys.count(Key::UP)) * MOVE_STEP;
		if (this->invincible) {
			if (last_sprite_index != 11) {
				last_sprite_index = sprite_index;
				sprite_index = 11;
			}
			else {
				sprite_index = last_sprite_index;
				if ((keys.count(Key::RIGHT) - keys.count(Key::LEFT)) != 0)
					sprite_index += (keys.count(Key::RIGHT) - keys.count(Key::LEFT));
				else
					if (sprite_index < 5)
						sprite_index += 1;
					else if (sprite_index > 5)
						sprite_index -= 1;
				sprite_index = min(10, max(0, sprite_index));
				last_sprite_index = sprite_index;
			}
		}
		else {
			if ((keys.count(Key::RIGHT) - keys.count(Key::LEFT)) != 0)
				sprite_index += (keys.count(Key::RIGHT) - keys.count(Key::LEFT));
				else
					if (sprite_index < 5)
						sprite_index += 1;
					else if (sprite_index > 5)
						sprite_index -= 1;

				sprite_index = min(10, max(0, sprite_index));
		}
		
		
		left = max(0, left);
		top = max(0, top);

		const double OFFSET = 1.5;
		left = min(SIZE_X - static_cast<int>(sprite.GetWidth() * OFFSET), left);
		top = min(SIZE_Y - static_cast<int>(sprite.GetHeight() * OFFSET), top);

		sprite.SetTopLeft(left, top);
		UpdateCollisionBox(left+this->sprite.GetWidth()/4, top + this->sprite.GetHeight() / 4);

		int fire_cooldown_milli = static_cast<int>(static_cast<double>(std::clock() - fire_cooldown_clock) / CLOCKS_PER_SEC * 1000);
		if (keys.count(Key::FIRE) && fire_cooldown_milli >= 300) {
			for (int i = 1; i <= level; ++i) {
				double angle = 0 + (180.0f/(level+1)) * i;
				double radians = angle * (M_PI / 180.0f);
				int index = bullets->AddElement();
				auto test = *bullets;
				test[index]->Init(true, bullet_type::straight_bullet);
				test[index]->SetTopLeft({ left + this->sprite.GetWidth() / 2-10+ static_cast<int>(50 * std::cos(radians)),top });
				test[index]->ApplyForce({ static_cast<int>(std::cos(radians) * 7), static_cast<int>(-std::sin(radians) * 7)-10});
			}
			fire_cooldown_clock = std::clock();
			attacking = true;
		}
	}

	void Player::UpdateByMouse(CPoint point)
	{
		sprite.SetTopLeft(point.x - sprite.GetWidth() / 2, point.y - sprite.GetWidth() / 2);
		UpdateCollisionBox(point.x - sprite.GetWidth() / 2, point.y - sprite.GetWidth() / 2);
		// TODO
	}

	bool Player::IsAttacking() const {
		return attacking;
	}

	void Player::fdajklgasjklsra() {
		bomb_count--;
	}
}
