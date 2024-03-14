#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	selector = 0;
	menuBackground.LoadBitmapByString({"Resources/images/bmp/menu.bmp"});
	menuBackground.SetTopLeft(0, 0);

	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			button[i].LoadBitmapByString({ "Resources/images/bmp/button-start.bmp",
														"Resources/images/bmp/button-start-hover.bmp" }, RGB(0, 0, 0));
		}
		else {
			button[i].LoadBitmapByString({ "Resources/images/bmp/button-quit.bmp",
														"Resources/images/bmp/button-quit-hover.bmp" }, RGB(0, 0, 0));
		}
			/*button[i].LoadBitmapByString({ "Resources/images/bmp/button.bmp",
										"Resources/images/bmp/button-hover.bmp" }, RGB(128, 128, 128));
		*/
		button[i].SetTopLeft(112, 355 + 90 * i);
	}

	Sleep(1000);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_UP) {
		selector -= 1;
	}

	if (nChar == VK_DOWN) {
		selector += 1;
	}

	if (nChar == VK_RETURN && selector == 0) {
		if(selector == 0) GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
		// if(selector == 1) exit(1);							// 結束程式
	}
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	//GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	if (selector > 1) selector = 1;
	if (selector < 0) selector = 0;
	menuBackground.ShowBitmap();

	if (selector == 0) {
		button[0].SetFrameIndexOfBitmap(1);
		button[1].SetFrameIndexOfBitmap(0);
	}
	else if (selector == 1) {
		button[0].SetFrameIndexOfBitmap(0);
		button[1].SetFrameIndexOfBitmap(1);
	}
	
	button[0].ShowBitmap();
	button[1].ShowBitmap();
}
