#pragma once
#include <../Library/gameutil.h>
namespace game_framework {
	class Point : public CMovingBitmap{
	public:
		//Point();
		void onInit();
		void setEnergizer(bool flag);
		void setEaten(bool flag);
		bool isOverlap(int leftX, int topY);
		bool isEnergizer();
		bool isEaten();
	protected:
		bool energizer;
		bool eaten;
	};
}
