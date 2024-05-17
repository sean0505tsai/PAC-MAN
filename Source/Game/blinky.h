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
		void setNextDirection(int direction);
		void moveByDirection(int moveDirection);
		//type«Ý­×¥¿
		//using Point = vector<int>;
		//vector<std::pair<int, int>> findShortestPath(int targetX, int targetY);
		void updateNextDirection(int targetX, int targetY);
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
		//void findRoute(int targetX, int targetY);
		//void findPacman();
		void setCurrentBlockType(int type);
	protected:
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
