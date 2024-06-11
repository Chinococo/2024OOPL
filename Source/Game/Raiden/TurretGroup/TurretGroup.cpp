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
				int x = elem->IntAttribute("x");  // 使用 IntAttribute 獲取 int 類型值
				int y = elem->IntAttribute("y");  // 使用 IntAttribute 獲取 int 類型值
				float bulletSpeed = elem->FloatAttribute("bulletSpeed");
				int angle = elem->IntAttribute("angle");  // 使用 IntAttribute 獲取 int 類型值
			

				CPoint position = { x, y };
				turrets.emplace_back(position, angle, bulletSpeed, bullets);
			}
		}
		else {
			// 處理讀取 XML 文件錯誤
		}
	}
	void TurretGroup::update(CPoint now) {
		for (auto& turret : turrets) {
			turret.update(std::move(now));
		}
	}

}