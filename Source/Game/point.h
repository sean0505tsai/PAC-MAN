#pragma once
#include <../Library/gameutil.h>
namespace game_framework {
	class Point : public CMovingBitmap{
	public:
		void onInit();
		void setEnergizer(bool flag);
		void setEaten(bool flag);
		bool isLevelPass();
		bool isEnergizer();
		bool isEaten();
	protected:
		bool energizer;
		bool eaten;
	};
}
