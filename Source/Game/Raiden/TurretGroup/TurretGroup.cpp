#include "stdafx.h"
#include "TurretGroup.h"
#include "../Xml/XmlReader.h"
namespace Raiden {
	TurretGroup::TurretGroup(std::shared_ptr<Raiden::GameObjectPool<Raiden::Bullet>>& bullets)
		: bullets(bullets) {}
	void TurretGroup::LoadFromXML(const std::string& filename) {
		tinyxml2::XMLDocument doc;
		if (doc.LoadFile(filename.c_str()) == tinyxml2::XML_SUCCESS) {
			tinyxml2::XMLElement* root = doc.RootElement();
			for (tinyxml2::XMLElement* elem = root->FirstChildElement("Turret"); elem != nullptr; elem = elem->NextSiblingElement("Turret")) {
				int x = elem->IntAttribute("x");  // �ϥ� IntAttribute ��� int ������
				int y = elem->IntAttribute("y");  // �ϥ� IntAttribute ��� int ������
				float bulletSpeed = elem->FloatAttribute("bulletSpeed");
				int directionX = elem->IntAttribute("directionX");  // �ϥ� IntAttribute ��� int ������
				int directionY = elem->IntAttribute("directionY");  // �ϥ� IntAttribute ��� int ������

				CPoint position = { x, y };
				CPoint direction = { directionX, directionY };
				turrets.emplace_back(position, direction, bulletSpeed, bullets);
			}
		}
		else {
			// �B�zŪ�� XML �����~
		}
	}
	void TurretGroup::update() {
		for (auto& turret : turrets) {
			turret.update();
		}
	}

}