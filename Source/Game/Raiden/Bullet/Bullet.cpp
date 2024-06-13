#include "stdafx.h"
#include "Bullet.h"
#include "../../config.h"
#include <limits>
namespace Raiden
{
	void Bullet::Init(bool friendly)
	{
		this->friendly = friendly;
		sprite.LoadBitmapByString({ "Resources/1.bmp" });
		collisionBox.Init({ { 0, 0, sprite.GetWidth(), sprite.GetWidth() } });
		alive = true;
	}

	void Bullet::Init(bool friendly, int type)
	{
		this->Init(friendly);
		this->type = type;
	}

	void Bullet::SetTopLeft(CPoint &&point)
	{
		sprite.SetTopLeft(std::move(point.x), std::move(point.y));
	}

	void Bullet::ApplyForce(CPoint &&force)
	{
		delta_left = std::move(force.x);
		delta_top = std::move(force.y);
		bullet_speed = static_cast<int>(std::round(std::sqrt(delta_left* delta_left + delta_top * delta_top)));
	}
	void Bullet::Update()
	{
		collisionBox.SetTopLeft(sprite.GetLeft() + delta_left, sprite.GetTop() + delta_top);
		std::pair<int, int> top_left = collisionBox.GetTopLeft();
		sprite.SetTopLeft(top_left.first, top_left.second);
	}

	void Bullet::Update(CPoint && player_pos, vector<CPoint>& enemy)
	{
		if (clock() - last_track_time  > 1000) {
			if (this->friendly) {
				UpdatePlayerBullet(enemy);
			}
			else {
				UpdateFighterBullet(player_pos);
			}
			last_track_time = clock();
		}
		collisionBox.SetTopLeft(sprite.GetLeft() + delta_left, sprite.GetTop() + delta_top);
		std::pair<int, int> top_left = collisionBox.GetTopLeft();
		sprite.SetTopLeft(top_left.first, top_left.second);
		
	}

	void Bullet::UpdatePlayerBullet(vector<CPoint>& enemy)
	{
		if (bullet_type::track_bullet == type) {
			if (enemy.empty()) return;

			int bullet_x = this->sprite.GetLeft();
			int bullet_y = this->sprite.GetTop();

			double min_distance = 1e9 + 7;
			CPoint* nearest_fighter = nullptr;

			for (auto& fighter : enemy) {
				int dx = fighter.x - bullet_x;
				int dy = fighter.y - bullet_y;
				double distance = std::sqrt(dx * dx + dy * dy);

				// 檢查敵人是否在200x200範圍內
				if (distance < min_distance && std::abs(dx) <= 150 && std::abs(dy) <= 150) {
					min_distance = distance;
					nearest_fighter = &fighter;
				}
			}
			if (nearest_fighter) {
				int dx = nearest_fighter->x - bullet_x;
				int dy = nearest_fighter->y - bullet_y;
				double distance = std::sqrt(dx * dx + dy * dy);

				if (distance != 0) {
					// Normalize the vector and scale by 5
					double unit_dx = dx / distance;
					double unit_dy = dy / distance;

					int force_x = static_cast<int>(unit_dx * 5);
					int force_y = static_cast<int>(unit_dy * 5);

					this->ApplyForce({ force_x, force_y });
				}
			}
		}

		
	}

	void Bullet::UpdateFighterBullet(CPoint& player_pos)
	{
		if (bullet_type::track_bullet == type) {
			int bullet_x = this->sprite.GetLeft();
			int bullet_y = this->sprite.GetTop();

			int dx = player_pos.x - bullet_x;
			int dy = player_pos.y - bullet_y;
			double distance = std::sqrt(dx * dx + dy * dy);

			const double max_tracking_range = 200.0;  // 定義追蹤範圍
			const double min_tracking_range = 100.0;  // 定義追蹤範圍

			if (distance > 0 && distance >= min_tracking_range && distance <= max_tracking_range && dx>0 && dy>0) {
				// Normalize the vector and scale by bullet speed
				int force_x = static_cast<int>(bullet_speed * bullet_speed);
				int force_y = static_cast<int>(bullet_speed * bullet_speed);

				this->ApplyForce(CPoint(force_x, force_y));
			}
		}
	}

	
	
	/*
	void Bullet::Update(Player& player, std::vector<std::shared_ptr<Fighter>>& fighters)
	{
		collisionBox.SetTopLeft(sprite.GetLeft() + delta_left, sprite.GetTop() + delta_top);
		std::pair<int, int> top_left = collisionBox.GetTopLeft();
		sprite.SetTopLeft(top_left.first, top_left.second);
	}*/

	void Bullet::Show()
	{
		sprite.ShowBitmap();
		collisionBox.Show();
	}

	CollisionBox &Bullet::GetCollisionBox()
	{
		return collisionBox;
	}

	bool Bullet::IsCollisionBoxOverlap(CollisionBox& other)
	{
		return collisionBox.IsCollisionBoxOverlap(other);
	}

	void Bullet::Destroy()
	{
		alive = false;
	}

	bool Bullet::IsAlive()
	{
		return alive;
	}
	bool Bullet::IsFriendly()
	{
		return friendly;
	}
	int Bullet::GetLeft()
	{
		return this->sprite.GetLeft();
	}
	int Bullet::GetTop()
	{
		return this->sprite.GetTop();
	}
}
