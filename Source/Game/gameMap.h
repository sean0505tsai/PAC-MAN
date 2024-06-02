#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Game/point.h"
#include "../Game/ghost.h"
#include "../Game/character.h"
#include <fstream>
#include <ctime>
#include <iostream>
#include <Windows.h>
#include "../Game/blinky.h"
// #include "../Library/gamecore.h"

namespace game_framework {

	class GameMap : public CMovingBitmap
	{
	public:
		GameMap();
		GameMap(int number);
		void setMazeNo(int number);
		void onInit();
		void onShow();
		void onMove();
		void togglePassAnimation();
		int isCollision(int x, int y, int speed, int direction);
		int getCurrentStage();
		int getBlockType(int x, int y);
		int getBlockTypeByIndex(int x, int y);
		int getTimerCount();

	protected:
		int stage;
		int mazeNo = 0;
		int mapMatrix[34][28] = { 0 };
		int lifeCount = 3;
		int timer = 0;
		DWORD timeStart;

		CMovingBitmap life[3];
		CMovingBitmap ready;
		enum stages{READY, RUNNING, PASS};
		void readMazeMatrix();
		//void loadLifeCountRES();	// to be removed
		void loadMazeRES();

		//void showLifeCount();	// to be removed
		void updateTimer();

	};
}


