#include "stdafx.h"
#include "ghost.h"
using namespace game_framework;

void ghost::onInit() {

}

void ghost::onMove() {

}

void ghost::onShow() {

}

void ghost::reset() {

}

bool ghost::isReverseDirection(int newdirection) {
	switch (newdirection)
	{
	case UP:
		reverseDirection = false ? direction == DOWN : true;
	case DOWN:
		reverseDirection = false ? direction == UP : true;
	case LEFT:
		reverseDirection = false ? direction == RIGHT : true;
		break;
	case RIGHT:
		reverseDirection = false ? direction == LEFT : true;
		break;
	}
	return reverseDirection;
}

int game_framework::ghost::getX() {
	return leftX;
}

int game_framework::ghost::getY() {
	return topY;
}

int game_framework::ghost::getRightX()
{
	return leftX + 19;
}

int game_framework::ghost::getBottomY()
{
	return topY + 19;
}

int game_framework::ghost::getSpeed()
{
	return speed;
}

int game_framework::ghost::getDirection()
{
	return direction;
}

int game_framework::ghost::getNextDirection(){
	return nextDirection;
}

void game_framework::ghost::setNextDirAVL(bool flag){
	nextDirectionAvailable = flag;
}

void ghost::teleport() {
	//«Ý­×§ï
	if (direction == LEFT) leftX = 520;
	else if (direction == RIGHT) leftX = 0;
}

void ghost::updateTimer(){
	DWORD end = GetTickCount();
	if (end - timerStart >= 1000) {	// 1000ms = 1sec
		timer++;
		timerStart = GetTickCount();		// update timer
	}
}

void ghost::setCurrentBlockType(int type) {
	currentBlockType = type;
}