#include "stdafx.h"
#include "blinky.h"
#include <queue>
#include <vector>
#include <utility>
#include <stack>
//#include <unordered_map>

using namespace game_framework;

void Blinky::onInit() {
	LoadBitmapByString({ "Resources/images/bmp/ghost-blinky-right.bmp" }, RGB(255, 255, 255));
	leftX = 270;
	//leftX = 120;
	topY = 280;
	speed = 4;
	collision = true;
	direction = RIGHT;
	state currentState = SCATTER;

	nextDirection = UP;
	nextDirectionAvailable = false;
}

void Blinky::moveUp() {
	if (collision == 0) {
			topY -= speed;
	}
	else if (collision != 1) {
			topY -= (collision - 1);
	}
}

void Blinky::moveDown() {
	if (collision == 0) {
		topY += speed;
	}
	else if (collision != 1) {
		topY += (collision - 1);
	}
}

void Blinky::moveLeft() {
	if (collision == 0) {
		leftX -= speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Blinky::moveRight() {
	if (collision == 0) {
		leftX += speed;
	}
	else if (collision != 1) {
		leftX += (collision - 1);
	}
}

void Blinky::setCurrentBlockType(int Type) {
	currentBlockType = Type;
}

void Blinky::onMove() {
	if (nextDirectionAvailable && nextDirection != direction) {
		direction = nextDirection;
	}
	else {
		switch (direction) {
		case UP:
			moveUp();
			break;
		case DOWN:
			moveDown();
			break;
		case LEFT:
			moveLeft();
			break;
		case RIGHT:
			moveRight();
			break;
		}
	}
}


vector<pair<int, int>> Blinky::findShortestPath(int targetX, int targetY) {
	int rows = 34;
	int cols = 28;
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, { -1, -1 }));

	queue<pair<int, int>> q;

	q.push({ leftX, topY });
	visited[topY][leftX] = true;

	int dirX[] = { 0, 0, -1, 1 }; // up, down, left, right
	int dirY[] = { -1, 1, 0, 0 }; // up, down, left, right

	bool found = false;

	while (!q.empty() && !found) {
		auto current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = current.second + dirY[i];
			int nextX = current.first + dirX[i];

			if (nextX >= 0 && nextX < targetX && nextY >= 0 && nextY < targetY &&
				(mapMatrix[nextY/20][nextX/20] == 0 || mapMatrix[nextY / 20][nextX / 20] == 2) && !visited[nextY][nextX]) {
				visited[nextY][nextX] = true;
				parent[nextY][nextX] = current;
				q.push({ nextX, nextY });

				if (nextX == targetX && nextY == targetY) {
					found = true;
					break;
				}
			}
		}
	}

	vector<pair<int, int>> path;

	if (found) {
		int x = targetX;
		int y = targetY;
		while (x != -1 && y != -1) {
			path.push_back({ x, y });
			auto p = parent[y][x];
			x = p.first;
			y = p.second;
		}

		reverse(path.begin(), path.end());
	}
	

	return path;
}

void Blinky::updateNextDirection(int targetX, int targetY) {
	vector<pair<int, int>> path = findShortestPath(targetX, targetY);

	if (path.empty() || path.size() < 2) {
		nextDirectionAvailable = false;
		return;
	}

	pair<int, int> nextStep = path[1]; // path[0] 是當前位置
	int nextX = nextStep.second;
	int nextY = nextStep.first;

	if (nextY < topY) {
		nextDirection = UP;
	}
	else if (nextY > topY) {
		nextDirection = DOWN;
	}
	else if (nextX < leftX) {
		nextDirection = LEFT;
	}
	else if (nextX > leftX) {
		nextDirection = RIGHT;
	}

	nextDirectionAvailable = true;
}



	/*Direction priority up(0) > left(2) > down(1) > right(3)*/

void Blinky::onShow() {
	showX = leftX - 9;
	showY = topY - 9;
	SetTopLeft(showX, showY);
	ShowBitmap();
}


/*void Blinky::findPacman() {

}*/

void Blinky::setNextDirection(int inputDirection) {
	// nextDIRinput = inputDirection;
	nextDirection = inputDirection;
}

void Blinky::setCollision(int flag) {
	collision = flag;
}

void Blinky::setMovingLeft(bool flag) {
	isMovingLeft = flag;
}

void Blinky::setMovingRight(bool flag) {
	isMovingRight = flag;
}

void Blinky::setMovingUp(bool flag) {
	isMovingUp = flag;
}

void Blinky::setMovingDown(bool flag) {
	isMovingDown = flag;
}

bool Blinky::getNextDirectionAVL() {
	return nextDirectionAvailable;
}