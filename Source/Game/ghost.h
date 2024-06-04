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
		int getX();			// 取得左上點X座標
		int getY();			// 取得左上點Y座標
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
		int leftX, topY;		// 左上點
		int rightX, bottomY;	// 右下點
		int showX, showY;		// 顯示用左上點
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
