#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Game/point.h"
#include "../Game/character.h"
#include <fstream>
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
		int getBlockType(int x, int y, int direction);
		void setCharacterMovement(int direction);
		// void 
	protected:
		int mazeNo;
		int mapMatrix[34][28] = { 0 };
		int lifeCount = 3;
		int pointCount;
		CMovingBitmap life[3];
		CMovingBitmap ready;
		Point dots[244];
		Character PacMan;
		enum stage{READY, RUNNING, OVER};
		void readMazeMatrix();
		void generateDots();

	private:
	};
}


