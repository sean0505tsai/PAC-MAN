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
// ï¿½oï¿½ï¿½classï¿½ï¿½ï¿½Cï¿½ï¿½ï¿½ï¿½ï¿½Cï¿½ï¿½ï¿½ï¿½ï¿½æª«ï¿½ï¿½Aï¿½Dï¿½nï¿½ï¿½ï¿½Cï¿½ï¿½ï¿½{ï¿½ï¿½ï¿½ï¿½ï¿½bï¿½oï¿½ï¿½
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
	if (lifeCount < 0) GotoGameState(GAME_STATE_OVER);
	////////////////////////*å°?ç²¾é??*////////////////////////
	int x = character.getX();
	int y = character.getY();
	int direction = character.getDirection();
	int CHARspeed = character.getSpeed();
	character.setCollision(maps.at(level).isCollision(x, y, CHARspeed, direction));
	character.setCurrentBlockType(maps.at(level).getBlockType(x, y));
	if (maps.at(level).isCollision(x, y, 2, character.getNextDirection()) != 1)	character.setNextDirAVL(true);
	else character.setNextDirAVL(false);

	int directions[] = { 0, 1, 2, 3};
	////////////////////////*ç´?é¬?*////////////////////////
	int blinkyX = blinky.getX();
	int blinkyY = blinky.getY();
	int blinkyDirection = blinky.getDirection();
	int blinkySpeed = blinky.getSpeed();
	int blinkyDirectionIndex = blinky.getDirectionIndex();
	int blinkyReverseIndex = blinky.reverseIndex();
	blinky.setCollision(maps.at(level).isCollision(blinkyX, blinkyY, blinkySpeed, blinkyDirection));
	blinky.setCurrentBlockType(maps.at(level).getBlockType(blinkyX, blinkyY));
	for (int i = 0; i < 4; i++) {
		if (i != blinkyDirectionIndex && i != blinkyReverseIndex) {
			blinky.setDirectionCollision(maps.at(level).isCollision(blinkyX, blinkyY, blinkySpeed, i), i);
		}
	}
	if (maps.at(level).isCollision(blinkyX, blinkyY, 2, blinky.getNextDirection()) != 1) blinky.setNextDirAVL(true);
	else blinky.setNextDirAVL(false);
	////////////////////////*ç²?é¬?*////////////////////////
	int pinkyX = pinky.getX();
	int pinkyY = pinky.getY();
	int pinkyDirection = pinky.getDirection();
	int pinkySpeed = pinky.getSpeed();
	int pinkyDirectionIndex = pinky.getDirectionIndex();
	int pinkyReverseIndex = pinky.reverseIndex();
	pinky.setCollision(maps.at(level).isCollision(pinkyX, pinkyY, pinkySpeed, pinkyDirection));
	pinky.setCurrentBlockType(maps.at(level).getBlockType(pinkyX, pinkyY));
	/*
	*/
	for (int i = 0; i < 4; i++) {
		if (i != pinkyDirectionIndex && i != pinkyReverseIndex) {
			pinky.setDirectionCollision(maps.at(level).isCollision(pinkyX, pinkyY, pinkySpeed, i), i);
		}
	}
	if (maps.at(level).isCollision(pinkyX, pinkyY, 2, pinky.getNextDirection()) != 1) pinky.setNextDirAVL(true);
	else pinky.setNextDirAVL(false);
	////////////////////////*???é¬?*////////////////////////
	int inkyX = inky.getX();
	int inkyY = inky.getY();
	int inkyDirection = inky.getDirection();
	int inkySpeed = inky.getSpeed();
	int inkyDirectionIndex = inky.getDirectionIndex();
	inky.setCollision(maps.at(level).isCollision(inkyX, inkyY, inkySpeed, inkyDirection));
	inky.setCurrentBlockType(maps.at(level).getBlockType(inkyX, inkyY));
	for (int i = 0; i < 4; i++) {
		if (i != inkyDirectionIndex) {
			inky.setDirectionCollision(maps.at(level).isCollision(inkyX, inkyY, inkySpeed, i), i);
		}
	}
	if (maps.at(level).isCollision(inkyX, inkyY, 2, inky.getNextDirection()) != 1) inky.setNextDirAVL(true);
	else inky.setNextDirAVL(false);
	////////////////////////*é»?é¬?*////////////////////////
	int clydeX = clyde.getX();
	int clydeY = clyde.getY();
	int clydeDirection = clyde.getDirection();
	int clydeSpeed = clyde.getSpeed();
	int clydeDirectionIndex = clyde.getDirectionIndex();
	clyde.setCollision(maps.at(level).isCollision(clydeX, clydeY, clydeSpeed, clydeDirection));
	clyde.setCurrentBlockType(maps.at(level).getBlockType(clydeX, clydeY));
	for (int i = 0; i < 4; i++) {
		if (i != clydeDirectionIndex) {
			clyde.setDirectionCollision(maps.at(level).isCollision(clydeX, clydeY, clydeSpeed, i), i);
		}
	}
	if (maps.at(level).isCollision(clydeX, clydeY, 2, clyde.getNextDirection()) != 1) clyde.setNextDirAVL(true);
	else clyde.setNextDirAVL(false);
	/*
	*/
	
	//0-up, 1-down, 2-left, 3-right
	/*
	//confirm whether the blinky can change direction
	if (maps.at(level).isCollision(blinkyX, blinkyY, 2, blinky.getNextDirection()) != 1) blinky.setNextDirAVL(true);
	else blinky.setNextDirAVL(false);
	blinky.onMove();
	//ï¿½pï¿½ï¿½ï¿½Fï¿½Ypoints
	*/
	maps.at(level).onMove();

	//blinky.setCollision(maps.at(level).isCollision(blinkyX, blinkyY, blinkySpeed, blinkyDirection));
	if (maps.at(level).getCurrentStage() == 1) {
		character.onMove();
		blinky.onMove();
		pinky.onMove();
		inky.onMove();
		clyde.onMove();
		/*
		*/
	}

	maps.at(level).onMove();
	checkDotsEaten(x, y);
	if (isLevelPass()) {
		if (level >= 20) {
			GotoGameState(GAME_STATE_OVER);
		}
		gotoNextLevel();
	}
	

}

void CGameStateRun::OnInit()
{
	/*map.LoadBitmapByString({ "Resources/images/bmp/board.bmp",
							"Resources/images/bmp/board-white.bmp" });
	map.SetTopLeft(0, 0);*/
	level = 0;
	dotCount = 0;
	levelPointCount = 0;
	lifeCount = 3;
	score = 0;

	// maps initialize
	for (int i = 0; i < 20; i++) {
		maps.emplace_back(i);
		maps.at(i).setMazeNo(i);
		maps.at(i).onInit();
	}

	loadLifeCountRES();
	character.onInit();
	blinky.onInit();
	pinky.onInit();
	generateDots();
	clyde.onInit();
	inky.onInit();
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
		gotoNextLevel();
	}
	if (nChar == 0x44) {	// D key
		character.die();
		lifeCount--;
	}
	if (nChar == 0x52) {	// R key
		character.reset();
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
	showLifeCount();
	showDots();
	character.onShow();
	blinky.onShow();
	clyde.onShow();
	inky.onShow();
	pinky.onShow();
	drawText("Score: " + std::to_string(levelPointCount), 280, 10);
	drawText("Total dots: " + std::to_string(dotCount), 280, 40);
	drawText("Level: " + std::to_string(level), 280, 70);

	// drawText("Timer: " + std::to_string(map.getTimerCount()), 10, 10);
	// drawText("actualX: " + std::to_string(character.getX()), 10, 10);
	// drawText("actualY: " + std::to_string(character.getY()), 10, 40);
	
	// drawText("Direction: " + std::to_string(character.getDirection()), 10, 70);
	
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
	
	*/
}

void CGameStateRun::drawText(string text, int x, int y){

	CDC* pDC = CDDraw::GetBackCDC();

	CTextDraw::ChangeFontLog(pDC, 20, "Segoe UI Black", RGB(255, 255, 255));
	CTextDraw::Print(pDC, x, y, text);
	CDDraw::ReleaseBackCDC();
}

void CGameStateRun::resetDots(){
	dotCount = 0;
	levelPointCount = 0;
	dots.clear();		// clear all dots
	// clear dots in maze and generate new ones
}

void CGameStateRun::generateDots(){
	// put dots in maze
	for (int i = 0; i < 34; i++) {
		for (int j = 0; j < 28; j++) {
			if (!((i >= 12 && i <= 22 && j >= 7 && j <= 20) || (i == 26 && (j == 13 || j == 14)))) {
				if (maps.at(level).getBlockTypeByIndex(i, j) == 0) {
					dots.emplace_back();
					dots[dotCount].onInit();
					if ((i == 5 && j == 1) || (i == 5 && j == 26) || (i == 26 && j == 1) || (i == 26 && j == 26)) {
						dots[dotCount].setEnergizer(true);
						dots[dotCount].SetTopLeft(j * 20 + 2, i * 20 + 2);
					}
					else {
						dots[dotCount].SetTopLeft(j * 20 + 7, i * 20 + 7);
					}
					dotCount++;
				}
			}
		}
	}
}

void CGameStateRun::showDots(){
	for (int i = 0; i < dotCount; i++) {
		dots.at(i).ShowBitmap();
	}
}

void CGameStateRun::checkDotsEaten(int x, int y){
	for (int i = 0; i < dotCount; i++) {
		if (dots[i].isOverlap(x, y)) {
			if (!dots[i].isEaten()) {
				levelPointCount++;
			}
			dots[i].setEaten(true);
		}
	}
}

bool CGameStateRun::isLevelPass(){
	return (levelPointCount >= dotCount) ? true : false;
	// 	if(levelPointCount >= dotCount)
	// return false;
}

void CGameStateRun::gotoNextLevel(){
	//maps.at(level).SetAnimation(50, true);
	//maps.at(level).ToggleAnimation();
	level++;
	dots.clear();
	dotCount = 0;
	levelPointCount = 0;
	generateDots();
	character.reset();
	blinky.reset();
	clyde.reset();
	pinky.reset();
	inky.reset();
	//maps.emplace_back();
	//maps.at(level).setMazeNo(level);
}

void CGameStateRun::gotoLastlevel(){

}

void CGameStateRun::loadLifeCountRES(){
	for (int i = 0; i < lifeCount; i++) {
		life.emplace_back();
		life[i].LoadBitmapByString({ "Resources/images/bmp/pacman/pacman-open-left.bmp" }, RGB(255, 255, 255));
		life[i].SetTopLeft(20 + 50 * i, 690);
	}
}

void CGameStateRun::showLifeCount(){
	for (int i = 0; i < lifeCount; i++) {
		life.at(i).ShowBitmap();
	}
}
