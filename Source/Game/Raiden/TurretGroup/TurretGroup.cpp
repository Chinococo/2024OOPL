#include "stdafx.h"
#include "TurretGroup.h"
#include "../Xml/XmlReader.h"
namespace Raiden {
	TurretGroup::TurretGroup(std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullets)
		: bullets(bullets) {}
	void TurretGroup::LoadFromXML(const std::string& filename, string name) {
		tinyxml2::XMLDocument doc;
		if (doc.LoadFile(filename.c_str()) == tinyxml2::XML_SUCCESS) {
			tinyxml2::XMLElement* configurationsElem = doc.RootElement();

			if (configurationsElem) {
				for (tinyxml2::XMLElement* configElem = configurationsElem->FirstChildElement("Configuration"); configElem != nullptr; configElem = configElem->NextSiblingElement("Configuration")) {
					const char* configName = configElem->Attribute("name");
					if (configName && name == configName) {
						tinyxml2::XMLElement* turretsElem = configElem->FirstChildElement("Turrets");
						for (tinyxml2::XMLElement* elem = turretsElem->FirstChildElement("Turret"); elem != nullptr; elem = elem->NextSiblingElement("Turret")) {
							int x = elem->IntAttribute("x");
							int y = elem->IntAttribute("y");
							float bulletSpeed = elem->FloatAttribute("bulletSpeed");
							int angle = elem->IntAttribute("angle");

							CPoint position = { x, y };
							turrets.emplace_back(position, angle, bulletSpeed, bullets);
						}
						break;  // 找到並加載特定配置後退出循環
					}
				}
			}
		}
	}
	void TurretGroup::update(CPoint now) {
		for (auto& turret : turrets) {
			turret.update(std::move(now));
		}
	}

}