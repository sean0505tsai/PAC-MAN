#pragma once
#include <../Library/gameutil.h>
namespace game_framework {
	class point : public CMovingBitmap{
	public:
		bool isEnergizer();
	protected:
		bool energizer;
	};
}
