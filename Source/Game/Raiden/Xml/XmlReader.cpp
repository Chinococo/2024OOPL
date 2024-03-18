#include "stdafx.h"
#include "XmlReader.h"
#include<string>
using namespace tinyxml2;

void XmlReader::ParseResourcesRootPath(XMLElement* root, std::map<std::string, std::string>& settings) {
	XMLElement* resourcesPathElem = root->FirstChildElement("ResourcesRootPath");
	if (resourcesPathElem) {
		const char* resourcesPath = resourcesPathElem->GetText();
		if (resourcesPath)
			settings["ResourcesRootPath"] = resourcesPath;
	}
}
void XmlReader::ParseEnemies(XMLElement* root, std::map<std::string, std::string>& settings) {
	XMLElement* spriteElem = root->FirstChildElement("Sprite");
	if (spriteElem) {
		XMLElement* enemiesElem = spriteElem->FirstChildElement("Enemies");
		if (enemiesElem) {
			for (XMLElement* enemyElem = enemiesElem->FirstChildElement("Enemy"); enemyElem; enemyElem = enemyElem->NextSiblingElement("Enemy")) {
				XMLElement* positionElem = enemyElem->FirstChildElement("Position");
				if (positionElem) {
					int x, y;
					positionElem->FirstChildElement("x")->QueryIntText(&x);
					positionElem->FirstChildElement("y")->QueryIntText(&y);
					settings["EnemyX"] = std::to_string(x);
					settings["EnemyY"] = std::to_string(y);
				}

				XMLElement* imageElem = enemyElem->FirstChildElement("Image");
				if (imageElem) {
					const char* imagePath = imageElem->GetText();
					if (imagePath)
						settings["EnemyImage"] = imagePath;
				}
			}
		}
	}
}