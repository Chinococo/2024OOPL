#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "Raiden/CollisionBox/CollisionBox.h"
#include "Raiden/Xml/XmlReader.h"
#include "Raiden/Xml/tinyxml2.h"
#include "Raiden/Control/Control.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	state_manager.Update(keys);
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile("Resources/GameSetting.xml") == tinyxml2::XML_SUCCESS) {
		Raiden::XmlReader reader;
		// Parse XML
		std::map<std::string, std::string> settings;
		std::vector<Raiden::Enemy_temp> Enemys;
		std::vector<Raiden::Figter_temp> Figter;
		tinyxml2::XMLElement* root = doc.FirstChildElement("GameSetting");
		if (root) {
			reader.ParseResourcesRootPath(root, settings);
			reader.ParseEnemies(root, Enemys);
			reader.ParseFigter(root, Figter);
		}
	}
	

	//Raiden::GameObjectPool<int> test;
	//test.AddElement({ 10,10 });
	bullet.AddElement({ 50,50 });
	bullet.AddElement({ 50,300 });
	state_manager.Init();
	key_map[VK_UP] = Raiden::Key::UP;
	key_map[VK_DOWN] = Raiden::Key::DOWN;
	key_map[VK_LEFT] = Raiden::Key::LEFT;
	key_map[VK_RIGHT] = Raiden::Key::RIGHT;
	key_map[0x5A] = Raiden::Key::FIRE;
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	keys.insert(key_map[nChar]);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	keys.erase(key_map[nChar]);
	state_manager.KeyUp(key_map[nChar]);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	state_manager.MouseMove(std::move(point));
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	state_manager.Show();
	//bullet.Update();
	bullet.Show();
}
