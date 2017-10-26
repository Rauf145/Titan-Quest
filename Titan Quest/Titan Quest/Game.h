#pragma once
#include "Player.h"
#include "Enemy.h"
class Game
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //*
	Player* player;
	vector<GameObject*> staticObjects;
	vector<Enemy*> enemies;
	Game()
	{
		Map::get();
		player = new Player;
	}
public:
	static Game& get();
	void DrawField();
	void DrawPlayer();
	//void DrawEnemies();
	Player* getPlayer();
};

