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

}

void ghost::setCurrentBlockType(int type) {
	currentBlockType = type;
}