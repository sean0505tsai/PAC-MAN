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
	int rows = mapMatrix.size();
	int cols = mapMatrix[0].size();

	// 將地圖座標轉成矩陣座標
	pair<int, int> startMatrix = { topY / 20, leftX / 20 };
	pair<int, int> endMatrix = { targetY / 20, targetX / 20 };

	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, { -1, -1 }));
	queue<pair<int, int>> q;

	q.push(startMatrix);
	visited[startMatrix.first][startMatrix.second] = true;

	int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  // 上下左右

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		// 如果到達終點
		if (curr == endMatrix) {
			break;
		}

		// 檢查四個方向
		for (auto dir : directions) {
			int newX = curr.first + dir[0];
			int newY = curr.second + dir[1];

			if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && mapMatrix[newX][newY] == 0 && !visited[newX][newY]) {
				q.push({ newX, newY });
				visited[newX][newY] = true;
				parent[newX][newY] = curr;
			}
		}
	}

	// 構造路徑
	vector<pair<int, int>> path;
	pair<int, int> step = endMatrix;

	if (!visited[step.first][step.second]) {
		return {}; // 無法到達終點
	}

	while (step != startMatrix) {
		path.push_back({ step.second * 20, step.first * 20 });
		step = parent[step.first][step.second];
	}
	path.push_back({ leftX, topY });
	reverse(path.begin(), path.end());

	return path;
}

/*
void Blinky::updateNextDirection(int turnX, int turnY) {
	if (leftX == turnX && topY == topY) {
		nextDirectionAvailable = true;
	}
}
*/

void Blinky::moveToTarget(int destX, int destY) {
	vector<pair<int, int>> path = findShortestPath(destX, destY);
	
	if (path.empty()) {
		// 无法到达目的地
		return;
	}

	pair<int, int> currentPos = { leftX, topY };

	// 遍历路径
	for (int i = 1; i < path.size() - 1; ++i) {
		pair<int, int> prev = path[i - 1];
		pair<int, int> curr = path[i];
		pair<int, int> next = path[i + 1];

		// 檢查是不是轉角節點
		if ((curr.second == prev.second && curr.first == next.first) ||
			(curr.first == prev.first && curr.second == next.second)) {

			// 當前座標等於轉角節點
			if (currentPos == curr) {
				// 计算新的方向
				if (curr.second == prev.second) {
					// 水平轉垂直
					nextDirection = (next.first < curr.first) ? UP : DOWN;
				}
				else if (curr.first == prev.first) {
					// 垂直轉水平
					nextDirection = (next.second > curr.second) ? RIGHT : LEFT;
				}
				nextDirectionAvailable = true;
			}
		}

		leftX = curr.first;
		topY = curr.second;
		currentPos = curr;
	}

	
	leftX = destX;
	topY = destY;
		
}

void Blinky::scatterMove() {
	vector<pair<int, int>> loopPath = {
		{420, 160},
		{420, 80},
		{520, 80},
		{520, 160}
	};

	// 移動至起點
	moveToTarget(420, 160);

	
	// 循環移動
	while (true) {
		if (leftX == 420 && topY == 160) {
			moveToTarget(420, 80);
		}
		else if (leftX == 420 && topY == 80) {
			moveToTarget(520, 80);
		}
		else if (leftX == 520 && topY == 80) {
			moveToTarget(520, 160);
		}
		else if (leftX == 520 && topY == 160) {
			moveToTarget(420, 160);
		}
	}
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