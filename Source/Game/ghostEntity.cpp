#include "stdafx.h"
#include <../Game/ghostEntity.h>

using namespace game_framework;

int ghostEntity::getState() {
	return currentState;
}

void ghostEntity::setCurrentTime(int time) {
	currentTime = time;
}

void ghostEntity::frighten(int second){
	currentState = FRIGHTEN;
	speed = 2;
	//record frightened mode start time(initialize)
	weakenStart = second;
	/*if (weakenStart == 0) {
		weakenStart = second;
	}*/
}

void ghostEntity::CountDown(){
	if (weakenStart != 0) {
		int period = currentTime - weakenStart;
		if (period == countDownStart) {
			currentState = COUNTDOWN;
		}
		else if (period == frightenTime) {
			currentState = SCATTER;
			weakenStart = 0;
			speed = 4;
		}
		
	}
}

void ghostEntity::setFrightenTime(int second){
	frightenTime = second;
	countDownStart = frightenTime * 0.7;
}

void game_framework::ghostEntity::setLevel(int level)
{
	currentLevel = level;
}
