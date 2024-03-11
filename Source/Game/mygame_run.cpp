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
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
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

void CGameStateRun::OnMove()							// ���ʹC������
{
	for (const std::unique_ptr<Raiden::Component> &component : components)
		component->Update();
	bullet1.Update(0,5);
	bullet2.Update(0,-5);
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
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

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
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
