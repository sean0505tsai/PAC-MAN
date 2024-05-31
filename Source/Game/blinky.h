#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
//#include <../Game/gameMap.h>  
namespace game_framework {
	class Blinky : public ghost {
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;

		// setter
		void reset();
		void moveOutSquare();
		int getDirectionIndex();
		bool newDirectionAvailable(int newdirection);
		void setDirectionCollision(int flag, int direction);
		void decideNextDirection();
		int reverseDirection();
		int reverseIndex();
		//vector<pair<int, int>> findShortestPath(int targetX, int targetY);
		void setNextDirection(int direction);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void setCollision(int flag);
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		bool getNextDirectionAVL();
		//void findPacman();
	protected:
		int newDirection;
		vector<pair<int, int>> road;
		//int currentBlockType;
		enum state { SCATTER, CHASE, FRIGHTEN, EATEN };
		int collision;
		int horDirection;
		int verDirection;
		int nextDIRinput;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
		CMovingBitmap dying;

		void loadUpRES();
		void loadDownRES();
		void loadLeftRES();
		void loadRightRES();
	};
}
