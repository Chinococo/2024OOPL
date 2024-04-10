#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "config.h"
#include <string>

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//����
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile("Resources\\Xml\\GameSetting.xml") == tinyxml2::XML_SUCCESS) {
		Raiden::XmlReader reader;
		// Parse XML
		std::map<std::string, std::string> settings;
		tinyxml2::XMLElement* root = doc.FirstChildElement("GameSetting");
		if (root) {
			tinyxml2::XMLElement* background = root->FirstChildElement("Background");
			if (background) {
				tinyxml2::XMLElement* path = background->FirstChildElement("Path");
				if (path) {
					std::string test = path->GetText();
					// Now test should contain "Background/"
				}
			}
		}
	}








	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(0, "Start Initialize...");	// �@�}�l��loading�i�׬�0%
	//
	// �}�l���J���
	//
	// Sleep(1000);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
	//
	std::vector<string> paths;

	for (int i = 1; i <= 4; i++)
		paths.push_back("Resources/Background/TitleScreen" + std::to_string(i) + ".bmp");

	title_screen.LoadBitmapByString(paths);
	title_screen.SetTopLeft(BACKGROUND_MARGIN, BACKGROUND_MARGIN);
	title_screen.SetAnimation(BACKGROUND_ANIMATION_DELAY_MILLI, true);
	title_screen.ToggleAnimation();
	logo.LoadBitmapByString({ "Resources/Background/NTUTLogo.bmp" });
	logo.SetTopLeft(SIZE_X - logo.GetWidth() - 18, SIZE_Y - logo.GetHeight() - 23);
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	clicked = nChar == 0x5A;
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	clicked = true;
}

void CGameStateInit::OnShow()
{
	title_screen.ShowBitmap();
	logo.ShowBitmap();

	if (!clicked)
		title_screen.ToggleAnimation();

	if (title_screen.IsAnimationDone())
		GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
}
