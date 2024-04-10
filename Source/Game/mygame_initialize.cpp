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
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//測試
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
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	// Sleep(1000);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
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
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}
