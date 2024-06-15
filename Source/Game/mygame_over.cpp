#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include <string>

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����������A(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g): CGameState(g)
{
}

void CGameStateOver::OnMove()
{
	//GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver::OnBeginState()
{
	
}

void CGameStateOver::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(66, "Initialize...");	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
	//
	// �}�l���J���
	//
	gameOver.LoadBitmapByString({ "Resources/images/bmp/game_over_white.bmp" });
	gameOver.SetTopLeft(100, 200);
	//
	// �̲׶i�׬�100%
	//
	ShowInitProgress(100, "OK!");

	Sleep(1000);
}

void CGameStateOver::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// if (nChar == VK_RETURN) GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver::OnShow()
{
	gameOver.ShowBitmap();
	drawText("Score: " + std::to_string(finalScore), 100, 250);
	if (isWin) {
		drawText("YOU PASSED ALL LEVELS.", 100, 290);
		// win animation
	}
	else {
		// lose animation
	}
	// drawText("Press ENTER to go back to menu.", 80, 600);
	
}
