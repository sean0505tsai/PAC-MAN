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

void CGameStateRun::OnMove()
{
	int x = character.getX();
	int y = character.getY();
	int direction = character.getDirection();
	int CHARspeed = character.getSpeed();
	character.setCollision(maps.at(level).isCollision(x, y, CHARspeed, direction));
	character.setCurrentBlockType(maps.at(level).getBlockType(x, y));
	if(maps.at(level).isCollision(x, y, 2,	character.getNextDirection()) != 1)	character.setNextDirAVL(true);
	else character.setNextDirAVL(false);
	

	int blinkyX = blinky.getX();
	int blinkyY = blinky.getY();
	int blinkyDirection = blinky.getDirection();
	int blinkySpeed = blinky.getSpeed();

	
	/*
	for (int i = 0; i < 4; i++) {
		blinky.setCollision(map.isCollision(blinkyX, blinkyY, blinkySpeed, i), i);
	}
	*/
	//�ˬd�H���e��V�M�t�ײ��ʬO�_����
	blinky.setCollision(map.isCollision(blinkyX, blinkyY, blinkySpeed, blinkyDirection));
	int availableDirection[4] = { 0, 1, 2, 3 };//0-up, 1-down, 2-left, 3-right

	/*
	*/
	//confirm whether the blinky can change direction
	if (map.isCollision(blinkyX, blinkyY, 2, blinky.getNextDirection()) != 1) blinky.setNextDirAVL(true);
	else blinky.setNextDirAVL(false);
	blinky.onMove();
	//�p���F�Ypoints
	map.onMove(character);
	// if (map.isLevelPass()) GotoGameState(GAME_STATE_OVER);

	blinky.setCollision(maps.at(level).isCollision(blinkyX, blinkyY, blinkySpeed, blinkyDirection));
	if (maps.at(level).isCollision(blinkyX, blinkyY, 2, blinky.getNextDirection()) != 1) blinky.setNextDirAVL(true);
	else blinky.setNextDirAVL(false);
	if (maps.at(level).getCurrentStage() == 1) {
		character.onMove();
		blinky.onMove();
	}
	maps.at(level).onMove(character);
	if (maps.at(level).isLevelPass()) GotoGameState(GAME_STATE_OVER);
	

}

void CGameStateRun::OnInit()
{
	/*map.LoadBitmapByString({ "Resources/images/bmp/board.bmp",
							"Resources/images/bmp/board-white.bmp" });
	map.SetTopLeft(0, 0);*/
	level = 0;
	for (int i = 0; i < 1; i++) {
		maps.emplace_back(i);
		maps.at(i).onInit();
		//map[i].onInit();
		//map[i].setMazeNo(i);
	}	
	character.onInit();
	clyde.onInit();
	blinky.onInit();
	inky.onInit();
	pinky.onInit();
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
	if (nChar == VK_NUMPAD4) {
		// last level
	}
	if (nChar == VK_NUMPAD6) {
		// next level
	}
	if (nChar == 0x44) {	// D key
		// character die
	}

}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // mouse input
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// mouse input
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// mouse input
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // mouse input
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// mouse input
{
}

void CGameStateRun::OnShow()
{
	maps.at(level).onShow();
	character.onShow();
	drawText("Score: " + std::to_string(maps.at(level).getCurrentScore()), 280, 10);
	// drawText("Timer: " + std::to_string(map.getTimerCount()), 10, 10);
	// drawText("actualX: " + std::to_string(character.getX()), 10, 10);
	// drawText("actualY: " + std::to_string(character.getY()), 10, 40);
	
	// drawText("Direction: " + std::to_string(character.getDirection()), 10, 70);
	blinky.onShow();
	clyde.onShow();
	inky.onShow();
	pinky.onShow();
	
	/*
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

	CTextDraw::ChangeFontLog(pDC, 20, "Segoe UI Black", RGB(255, 255, 255));
	CTextDraw::Print(pDC, x, y, text);
	CDDraw::ReleaseBackCDC();
}
