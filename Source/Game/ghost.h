#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include <vector>
#include <Windows.h>
// #include "../Library/gamecore.h"

namespace game_framework {
	
	class ghost : public CMovingBitmap {
	public:
		virtual void onInit();
		virtual void onMove();
		virtual void onShow();
		virtual void reset();
		int getX();			// ���o���W�IX�y��
		int getY();			// ���o���W�IY�y��
		int getRightX();
		int getBottomY();
		int getSpeed();
		int getDirection();
		int getNextDirection();
		bool isReverseDirection(int newdirection);
		void setNextDirAVL(bool flag);
		void setCurrentBlockType(int type);

	protected:
		vector<int> directions = { UP, DOWN, LEFT, RIGHT };
		int leftX, topY;		// ���W�I
		int rightX, bottomY;	// �k�U�I
		int showX, showY;		// ��ܥΥ��W�I
		int speed;
		int direction;
		int newDirection;
		int directionIndex;
		bool upCollision;
		bool downCollision;
		bool leftCollision;
		bool rightCollision;
		bool reverseDirection;
		int nextDirection;
		int currentBlockType;
		bool nextDirectionAvailable;

		enum directions{ UP, DOWN, LEFT, RIGHT};
		CMovingBitmap movingUp;
		CMovingBitmap movingDown;
		CMovingBitmap movingLeft;
		CMovingBitmap movingRight;
		void teleport();

		int timer = 0;
		DWORD timerStart;
		void updateTimer();
	};

}
