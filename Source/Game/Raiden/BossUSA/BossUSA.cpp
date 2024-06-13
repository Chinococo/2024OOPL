#include "stdafx.h"
#include "BossUSA.h"
#include <random>
namespace Raiden
{
	void BossUSA::LoadTurretGroup()
	{
		turretGroups.push_back(new TurretGroup(bullets));
		turretGroups[turretGroups.size() - 1]->LoadFromXML("Resources/turret/BossUSA.xml", "Setup1");
		turretGroups.push_back(new TurretGroup(bullets));
		turretGroups[turretGroups.size() - 1]->LoadFromXML("Resources/turret/BossUSA.xml", "Setup2");
	}
	void BossUSA::Attack(const Player &player)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(1, 10); // 使用更大的範圍

		int random_number = dis(gen);
		bullet_type type;

		if (random_number <= 8) {
			type = track_bullet;
		}
		else {
			type = straight_bullet;
		}
		int index = bullets->AddElement();
		bullets->operator[](index)->Init(false, type);

		CPoint bullet_pos = { sprite.GetLeft(), sprite.GetTop() };
		auto _player = player;
		auto player_pos = _player.GetTopLeft();
		CPoint direction = player_pos - bullet_pos;
		if (direction.y > 0) {
			bullets->operator[](index)->SetTopLeft({ sprite.GetLeft() + sprite.GetWidth() / 2, sprite.GetTop() + sprite.GetHeight() + 50 });
		}
		else {
			bullets->operator[](index)->SetTopLeft({ sprite.GetLeft() + sprite.GetWidth() / 2, sprite.GetTop() - 50 });
		}

		double distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

		if (distance != 0) {
			// Normalize the vector and scale by 5
			double unit_dx = direction.x / distance;
			double unit_dy = direction.y / distance;

			int force_x = static_cast<int>(unit_dx * 5);
			int force_y = static_cast<int>(unit_dy * 5);

			bullets->operator[](index)->ApplyForce({ force_x, force_y });
		}

		
	}
}
