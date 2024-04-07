#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
// #include "../Library/gamecore.h"

namespace game_framework {
	
	class ghost : public CMovingBitmap {
	public:
		virtual void onInit();
		virtual void onMove();
		virtual void onShow();

	protected:
		int leftX, topY;		// ���W�I
		int rightX, bottomY;	// �k�U�I
		int centerX, centerY;	// �����I
		int showX, showY;		// ��ܥΥ��W�I
		int speed;
		int direction;
		int nextDirection;
		bool collision;
		enum directions{ UP, DOWN, LEFT, RIGHT};
	};

}
