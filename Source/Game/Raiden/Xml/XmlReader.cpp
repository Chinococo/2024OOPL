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
	void XmlReader::ParseEnemies(XMLElement* root, std::vector<Enemy_temp>& Enemys) {
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
						//XMLElement* start_move_time_elememt = position_elememt->FirstChildElement("StartMoveTime");
						//XMLElement* tick_elememt = position_elememt->FirstChildElement("Tick");
						//XMLElement* position_index_elememt = position_elememt->FirstChildElement("PositionIndex");

						// Check and process left_elememt
						if (left_elememt) {
							left_elememt->QueryIntText(&x);
						}

						// Check and process top_elememt
						if (top_elememt) {
							top_elememt->QueryIntText(&y);
						}

						// Check and process start_move_time_elememt
						//if (start_move_time_elememt) {
						//	start_move_time_elememt->QueryIntText(&startMoveTime);
						//}

						// Check and process tick_elememt
						//if (tick_elememt) {
						//	tick_elememt->QueryIntText(&tick);
						//}

						// Check and process position_index_elememt
						//if (position_index_elememt) {
						//	position_index_elememt->QueryIntText(&positionIndex);
						//}

						// Create and add new Enemy_temp object only if all elements exist
						if (left_elememt && top_elememt/* && start_move_time_elememt && tick_elememt && position_index_elememt*/) {
							Enemy_temp newEnemy(x, y/*, startMoveTime, tick, positionIndex*/);
							Enemys.push_back(newEnemy); // Add EnemyX data to the vector
						}

					}
				}
			}
		}
	}

}