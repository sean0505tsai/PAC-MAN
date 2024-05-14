#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Game/point.h"
#include "../Game/character.h"
#include <fstream>
#include <ctime>
// #include "../Library/gamecore.h"

namespace game_framework {

	class GameMap : public CMovingBitmap
	{
	public:
		void setMazeNo(int number);
		void onInit();
		void onShow();
		void onMove(Character pacMan);
		bool isLevelPass();
		int isCollision(int x, int y, int speed, int direction);
		int getCurrentScore();
		int getBlockType(int x, int y);
		int getTimerCount();
		// void setCharacterMovement(int direction);
		// void 
	protected:
		int stage;
		int mazeNo;
		int mapMatrix[34][28] = { 0 };
		int lifeCount = 3;
		int pointCount;
		int timer;

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

	private:
	};
}


