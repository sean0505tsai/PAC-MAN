#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
namespace game_framework {
	class ghostEntity : public ghost{
	public:
		int getState();

	protected:
		int currentState;
		enum state { SCATTER, CHASE, FRIGHTEN, EATEN, COUNTDOWN };

		int weakenstart = 0;
		int currentTime;
	};
}

