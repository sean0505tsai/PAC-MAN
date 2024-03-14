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
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(0, "Start Initialize...");	// �@�}�l��loading�i�׬�0%
	//
	// �}�l���J���
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

	Sleep(1000);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
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
		if(selector == 0) GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
		// if(selector == 1) exit(1);							// �����{��
	}
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	//GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
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
