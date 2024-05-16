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
	}
	void Bullet::Update()
	{
		collisionBox.SetTopLeft(sprite.GetLeft() + delta_left, sprite.GetTop() + delta_top);
		std::pair<int, int> top_left = collisionBox.GetTopLeft();
		sprite.SetTopLeft(top_left.first, top_left.second);
	}

	void Bullet::Update(CPoint && player_pos, vector<CPoint>& fighter_pos)
	{
		if (clock() - last_track_time  > 300) {
			if (this->friendly) {
				UpdatePlayerBullet(fighter_pos);
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

	void Bullet::UpdatePlayerBullet(vector<CPoint>& fighter_pos)
	{
		if (bullet_type::track_bullet == type) {
			if (fighter_pos.empty()) return;

			int bullet_x = this->sprite.GetLeft();
			int bullet_y = this->sprite.GetTop();

			double min_distance = 1e9 + 7;
			CPoint* nearest_fighter = nullptr;

			for (auto& fighter : fighter_pos) {
				int dx = fighter.x - bullet_x;
				int dy = fighter.y - bullet_y;
				double distance = std::sqrt(dx * dx + dy * dy);

				if (distance < min_distance) {
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

					int force_x = static_cast<int>(unit_dx * 3);
					int force_y = static_cast<int>(unit_dy * 3);

					this->ApplyForce({ force_x, force_y });
				}
			}
		}
		
	}

	void Bullet::UpdateFighterBullet(CPoint& player_pos)
	{
		
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
