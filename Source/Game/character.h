#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
namespace game_framework {
	class Character : public ghost{
	public:
		void onInit() override;
		void onMove() override;
		void onShow() override;
		void reset() override;
		
		// setter
		void setNextDirection(int direction);
		void setCollision(int flag);
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		bool getNextDirectionAVL();
	
	protected:
		enum state{ NORMAL, WEAK, DIE };
		int collision;
		int nextDIRinput;
		int currentState;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isMovingDown;
		CMovingBitmap dying;
		
		void loadUpRES();
		void loadDownRES();
		void loadLeftRES();
		void loadRightRES();
		void loadDyingRES();
		// void teleport() override;

	};
}
