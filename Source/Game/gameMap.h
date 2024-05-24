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
		void onMove(Character pacMan);
		//void onMOve(Blinky blinky);
		bool isLevelPass();
		int isCollision(int x, int y, int speed, int direction);
		int getCurrentScore();
		int getCurrentStage();
		int getBlockType(int x, int y);
		int getBlockTypeByIndex(int row, int column);
		int getTimerCount();
		// void setCharacterMovement(int direction);
		// void 
	protected:
		int stage;
		int mazeNo = 0;
		int mapMatrix[34][28] = { 0 };
		int lifeCount = 3;
		int pointCount;
		int timer = 0;
		DWORD timeStart;

		CMovingBitmap life[3];
		CMovingBitmap ready;
		Point dots[244];
		// Character PacMan;
		enum stages{READY, RUNNING, OVER};
		void readMazeMatrix();
		void generateDots();
		void loadLifeCountRES();
		void loadMazeRES();

		void showDots();
		void showLifeCount();
		void checkDotsEaten(int x, int y);
		void updateTimer();

	private:
	};
}


