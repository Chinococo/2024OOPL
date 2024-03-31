#include "stdafx.h"
#include "XmlReader.h"
#include <string>
#include <exception>

namespace Raiden
{
	std::map<std::string, std::string> XmlReader::ParseResourcesRootPath(tinyxml2::XMLElement* root)
	{
		std::string key = "ResourcesRootPath";

		tinyxml2::XMLElement* resource_path_elem = root->FirstChildElement(key.c_str());

		if (!resource_path_elem)
			throw std::invalid_argument("Invalid resource path data.");

		std::string resource_path = resource_path_elem->GetText();

		if (resource_path.empty())
			throw std::invalid_argument("The resource path is empty.");

		std::map<std::string, std::string> settings;
		settings[key] = resource_path;

		return settings;
	}

	std::vector<Enemy_temp> XmlReader::ParseEnemies(tinyxml2::XMLElement* root)
	{
		tinyxml2::XMLElement* sprite_elem = root->FirstChildElement("Sprite");

		if (!sprite_elem)
			throw std::invalid_argument("Invalid sprite data.");

		tinyxml2::XMLElement* enemies_elem = sprite_elem->FirstChildElement("Enemies");

		if (!enemies_elem)
			throw std::invalid_argument("Invalid enemies.");

		tinyxml2::XMLElement* enemy_elem = enemies_elem->FirstChildElement("Enemy");

		std::vector<Enemy_temp> enemies;

		while (enemy_elem)
		{
			tinyxml2::XMLElement* position_elem = enemy_elem->FirstChildElement("Position");

			if (!position_elem)
				continue;

			int left = 0;
			int top = 0;
			int tick = 0;
			int position_index = 0;

			tinyxml2::XMLElement* left_elem = position_elem->FirstChildElement("Left");
			tinyxml2::XMLElement* top_elem = position_elem->FirstChildElement("Top");

			// Create and add new Enemy_temp object only if all elements exist
			if (left_elem && top_elem /* && start_move_time_elem && tick_elem && position_index_elem */ )
			{
				left_elem->QueryIntText(&left);
				top_elem->QueryIntText(&top);

				// Add EnemyX data to the vector
				enemies.push_back(Enemy_temp(left, top));
			}

			enemy_elem = enemy_elem->NextSiblingElement("Enemy");
		}

		return enemies;
	}

	std::vector<Figter_temp> XmlReader::ParseFigter(tinyxml2::XMLElement* root)
	{
		tinyxml2::XMLElement* sprite_elem = root->FirstChildElement("Sprite");

		if (!sprite_elem)
			throw std::invalid_argument("Invalid sprite data.");

		tinyxml2::XMLElement* fighters_elem = sprite_elem->FirstChildElement("Fighters");

		if (!fighters_elem)
			throw std::invalid_argument("Invalid fighters data.");

		tinyxml2::XMLElement* fighter_elem = fighters_elem->FirstChildElement("Fighter");

		std::vector<Figter_temp> fighters;

		while (fighter_elem)
		{
			tinyxml2::XMLElement* position_elem = fighter_elem->FirstChildElement("Position");

			if (!position_elem)
				continue;

			int left = 0;
			int top = 0;
			int start_move_time = 0;
			int tick = 0;
			int position_index = 0;

			tinyxml2::XMLElement* left_elem = position_elem->FirstChildElement("Left");
			tinyxml2::XMLElement* top_elem = position_elem->FirstChildElement("Top");
			tinyxml2::XMLElement* start_move_time_elem = position_elem->FirstChildElement("StartMoveTime");
			tinyxml2::XMLElement* tick_elem = position_elem->FirstChildElement("Tick");
			tinyxml2::XMLElement* position_index_elem = position_elem->FirstChildElement("PositionIndex");

			if (left_elem && top_elem && start_move_time_elem && tick_elem && position_index_elem)
			{
				left_elem->QueryIntText(&left);
				top_elem->QueryIntText(&top);
				start_move_time_elem->QueryIntText(&start_move_time);
				tick_elem->QueryIntText(&tick);
				position_index_elem->QueryIntText(&position_index);

				fighters.push_back(Figter_temp(x, y, start_move_time, tick, position_index)); // Add EnemyX data to the vector
			}
			
			fighter_elem = fighter_elem->NextSiblingElement("Fighter");
		}

		return fighters;
	}
}
