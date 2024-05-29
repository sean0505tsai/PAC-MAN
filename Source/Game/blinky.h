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
		int getDirectionIndex();
		bool newDirectionAvailable(int newdirection);
		//vector<pair<int, int>> findShortestPath(int targetX, int targetY);
		void setNextDirection(int direction);
		void decideNextDirection();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void setCollision(int flag);
		void setDirectionCollision(int flag, int direction);
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		bool getNextDirectionAVL();
		//void findPacman();
		void setCurrentBlockType(int type);
	protected:
		int newDirection;
		vector<pair<int, int>> road;
		int currentBlockType;
		enum state { SCATTER, CHASE, FRIGHTEN, EATEN };
		int collision;
		int horDirection;
		int verDirection;
		int nextDIRinput;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
		
	};
}
