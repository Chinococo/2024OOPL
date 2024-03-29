#include "stdafx.h"
#include "XmlReader.h"
#include "../Enemy/Enemy.h"
#include<string>
#include <list>
using namespace tinyxml2;
namespace Raiden {
	
	void XmlReader::ParseResourcesRootPath(XMLElement* root, std::map<std::string, std::string>& settings) {
		XMLElement* resourcesPathElem = root->FirstChildElement("ResourcesRootPath");
		if (resourcesPathElem) {
			const char* resourcesPath = resourcesPathElem->GetText();
			if (resourcesPath)
				settings["ResourcesRootPath"] = resourcesPath;
		}
	}
	void XmlReader::ParseEnemies(tinyxml2::XMLElement* root, std::vector<Enemy_temp>& Enemys) {
		XMLElement* spriteElem = root->FirstChildElement("Sprite");
		if (spriteElem) {
			XMLElement* enemiesElem = spriteElem->FirstChildElement("Enemies");
			if (enemiesElem) {
				for (XMLElement* enemyElem = enemiesElem->FirstChildElement("Enemy"); enemyElem; enemyElem = enemyElem->NextSiblingElement("Enemy")) {
					XMLElement* position_elememt = enemyElem->FirstChildElement("Position");
					if (position_elememt) {
						int x = 0, y = 0, startMoveTime = 0, tick = 0, positionIndex = 0;
						XMLElement* left_elememt = position_elememt->FirstChildElement("Left");
						XMLElement* top_elememt = position_elememt->FirstChildElement("Top");
						// Create and add new Enemy_temp object only if all elements exist
						if (left_elememt && top_elememt/* && start_move_time_elememt && tick_elememt && position_index_elememt*/) {
							left_elememt->QueryIntText(&x);
							top_elememt->QueryIntText(&y);
							Enemy_temp newEnemy(x, y);
							Enemys.push_back(newEnemy); // Add EnemyX data to the vector
						}

					}
				}
			}
		}
	}
	void XmlReader::ParseFigter(XMLElement* root, std::vector<Figter_temp>& figters) {
		XMLElement* spriteElem = root->FirstChildElement("Sprite");
		if (spriteElem) {
			XMLElement* fighters_element = spriteElem->FirstChildElement("Fighters");
			if (fighters_element) {
				for (XMLElement* fighter_element = fighters_element->FirstChildElement("Fighter"); fighter_element; fighter_element = fighter_element->NextSiblingElement("Fighter")) {
					XMLElement* position_elememt = fighter_element->FirstChildElement("Position");
					if (position_elememt) {
						int x = 0, y = 0, startMoveTime = 0, tick = 0, positionIndex = 0;
						XMLElement* left_elememt = position_elememt->FirstChildElement("Left");
						XMLElement* top_elememt = position_elememt->FirstChildElement("Top");
						XMLElement* start_move_time_elememt = position_elememt->FirstChildElement("StartMoveTime");
						XMLElement* tick_elememt = position_elememt->FirstChildElement("Tick");
						XMLElement* position_index_elememt = position_elememt->FirstChildElement("PositionIndex");
						if (left_elememt && top_elememt && start_move_time_elememt && tick_elememt && position_index_elememt) {
							left_elememt->QueryIntText(&x);
							top_elememt->QueryIntText(&y);
							start_move_time_elememt->QueryIntText(&startMoveTime);
							tick_elememt->QueryIntText(&tick);
							position_index_elememt->QueryIntText(&positionIndex);
							Figter_temp new_figter_temp(x, y, startMoveTime, tick, positionIndex);
							figters.push_back(new_figter_temp); // Add EnemyX data to the vector
						}
					}
				}
			}
		}
	}

}