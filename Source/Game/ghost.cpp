#include "stdafx.h"
#include "ghost.h"
#include<queue>
using namespace game_framework;

void ghost::onInit() {

}

void ghost::onMove() {

}

void ghost::onShow() {

}

void ghost::reset() {

}

//find the shortest path
vector<pair<int, int>> ghost::findShortestPath(int desX, int desY) {
	int n = 23;
	int m = 34;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, pair<int,int>(-1, -1)));
	queue<pair<int, int>> q;
	pair<int, int> start({ leftX, topY });
	q.push(start);
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		if (curr.first == desX && curr.second == desY) {
			break;
		}

	}
	vector<pair<int, int>> path;

	return path;
}
/*
*/

int game_framework::ghost::getX() {
	return leftX;
}

int game_framework::ghost::getY() {
	return topY;
}

int game_framework::ghost::getRightX()
{
	return leftX + 19;
}

int game_framework::ghost::getBottomY()
{
	return topY + 19;
}

int game_framework::ghost::getSpeed()
{
	return speed;
}

int game_framework::ghost::getDirection()
{
	return direction;
}

int game_framework::ghost::getNextDirection(){
	return nextDirection;
}

void game_framework::ghost::setNextDirAVL(bool flag){
	nextDirectionAvailable = flag;
}

void ghost::teleport() {
	if (direction == LEFT) leftX = 520;
	else if (direction == RIGHT) leftX = 0;
}

void ghost::setCurrentBlockType(int type) {
	currentBlockType = type;
}