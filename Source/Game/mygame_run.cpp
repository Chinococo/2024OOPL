#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "Raiden/CollisionBox/CollisionBox.h"

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
	bullet[0]->Update(0, 5);
	bullet[1]->Update(0, -5);
	manager.Update(keys);
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	//Raiden::GameObjectPool<int> test;
	//test.AddElement({ 10,10 });
	bullet.AddElement({ 50,50 });
	bullet.AddElement({ 50,300 });
	manager.Init();
	keyMap[VK_UP] = Raiden::Key::UP;
	keyMap[VK_DOWN] = Raiden::Key::DOWN;
	keyMap[VK_LEFT] = Raiden::Key::LEFT;
	keyMap[VK_RIGHT] = Raiden::Key::RIGHT;
	keyMap[0x5A] = Raiden::Key::FIRE;
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	keys.insert(keyMap[nChar]);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	keys.erase(keyMap[nChar]);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	bullet.Update();
	bullet.Show();
	bool check = bullet[0]->IsCollisionBoxOverlap(*bullet[1]);
	if (check) {
		std::wstring info = L"collison";
		OutputDebugStringW(info.c_str());
	}
	manager.Show();
}
