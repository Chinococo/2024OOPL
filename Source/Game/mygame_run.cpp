#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "Raiden/Component.hpp"
#include "Raiden/Background/Background.hpp"
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
	for (const std::unique_ptr<Raiden::Component> &component : components)
		component->Update();
	bullet1.Update(0,5);
	bullet2.Update(0,-5);
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	components.push_back(std::make_unique<Raiden::Background>());
	for (const std::unique_ptr<Raiden::Component> &component : components)
		component->Init();
	bullet1.Init(50,50);
	bullet2.Init(50,300);
	
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
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
	for (const std::unique_ptr<Raiden::Component> &component : components)
		component->Show();
	bullet1.Show();
	bullet2.Show();
	bool check = bullet1.IsCollisionBoxOverlap(bullet2);
	if (check) {
		printf("collison");
	}
}
