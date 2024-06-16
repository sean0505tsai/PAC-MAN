#pragma once
#include <../Library/gameutil.h>
#include <../Game/ghost.h>
namespace game_framework {
	class ghostEntity : public ghost{
	public:
		// getter
		int getState();

		// move control

		// timer
		void setCurrentTime(int time);
		void frighten(int second);
		void CountDown();
		void setFrightenTime(int second);
		void setLevel(int level);

	protected:
		int currentState;
		enum state { SCATTER, CHASE, FRIGHTEN, EATEN, COUNTDOWN };

		int weakenStart = 0;
		int currentTime;
		int spawnTime;
		int frightenTime;
		int countDownStart;
		int currentLevel;
	};
}
