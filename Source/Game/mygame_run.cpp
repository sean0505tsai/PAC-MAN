#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

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
	int x = character.getX();
	int y = character.getY();
	int direction = character.getDirection();
	int CHARspeed = character.getSpeed();
	character.setCollision(map.isCollision(x, y, CHARspeed, direction));
	if(map.isCollision(x, y, 2,	character.getNextDirection()) != 1)	character.setNextDirAVL(true);
	else character.setNextDirAVL(false);
	character.onMove();
	map.onMove(character);
	if (map.isLevelPass()) GotoGameState(GAME_STATE_OVER);
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	/*map.LoadBitmapByString({ "Resources/images/bmp/board.bmp",
							"Resources/images/bmp/board-white.bmp" });
	map.SetTopLeft(0, 0);*/
	map.onInit();
	map.setMazeNo(0);
	character.onInit();
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_UP) {
		character.setNextDirection(0);	// UP: 0
	}
	if (nChar == VK_DOWN) {
		character.setNextDirection(1);	// DOWN: 1
	}
	if (nChar == VK_LEFT) {
		character.setNextDirection(2);	// LEFT: 2
	}
	if (nChar == VK_RIGHT) {
		character.setNextDirection(3);	// RIGHT: 3
	}
	
	/*
	if (nChar == VK_LEFT) {
		character.setMovingLeft(true);
	}
	if (nChar == VK_RIGHT) {
		character.setMovingRight(true);
	}
	if (nChar == VK_UP) {
		character.setMovingUp(true);
	}
	if (nChar == VK_DOWN) {
		character.setMovingDown(true);
	}
	*/
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	/*
	if (nChar == VK_LEFT) {
		character.setMovingLeft(false);
	}
	if (nChar == VK_RIGHT) {
		character.setMovingRight(false);
	}
	if (nChar == VK_UP) {
		character.setMovingUp(false);
	}
	if (nChar == VK_DOWN) {
		character.setMovingDown(false);
	}
	*/
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
	map.onShow();
	character.onShow();
	drawText("Score: " + std::to_string(map.getCurrentScore()), 280, 10);
	/*
	drawText("actualX: " + std::to_string(character.getX()), 10, 10);
	drawText("actualY: " + std::to_string(character.getY()), 10, 40);
	/*
	drawText("Direction: " + std::to_string(character.getDirection()), 10, 70);
	drawText("Collision: " + std::to_string(map.isCollision(character.getX(), character.getY(),
											character.getSpeed(), character.getDirection())), 10, 100);
	std::string nextDIR = "";
	switch (character.getNextDirection()) {
	case 0: nextDIR = "UP";
	case 1: nextDIR = "DOWN";
	case 2: nextDIR = "LEFT";
	case 3: nextDIR = "RIGHT";
	}
	drawText("Next Direction: " + std::to_string(character.getNextDirection()), 10, 130);
	if (map.isCollision(character.getX(), character.getY(),
		character.getSpeed(), character.getNextDirection()) == 1) {
		drawText("Next Dir. AVL.: false", 10, 160);
	}else drawText("Next Dir. AVL.: true", 10, 160);
	
	drawText("Speed: " + std::to_string(character.getSpeed()), 10, 190);
	*/
}

void CGameStateRun::drawText(string text, int x, int y){

	CDC* pDC = CDDraw::GetBackCDC();

	CTextDraw::ChangeFontLog(pDC, 20, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, x, y, text);
	CDDraw::ReleaseBackCDC();
}
