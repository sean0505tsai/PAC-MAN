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
		//void setDirectionIndex();
		//vector<pair<int, int>> findShortestPath(int targetX, int targetY);
		void setNextDirection(int direction);
		void decideNextDirection();
		void scatterMove();
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
		bool upAvailable;
		bool downAvailable;
		bool leftAvailable;
		bool rightAvailable;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
		
	};
}
