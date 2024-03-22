#pragma once
#include "../Library/audio.h"
#include "../Library/gameutil.h"
// #include "../Library/gamecore.h"

namespace game_framework {
	
	class ghost : public CMovingBitmap {
	public:
		virtual void onMove();

	protected:
		int speed;
		enum direction{ UP, DOWN, LEFT, RIGHT};
	};

}

