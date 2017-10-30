#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Zombie.h"
class Game
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //*
	Player* player;
	vector<GameObject*> staticObjects;
	vector<Enemy*> enemies;
	Game()
	{
		Enemy *EnemyType;
		Map::get();
		player = new Player;
		for (int i = 0; i < 20; i++)
		{
			Damage dm;//	 Temperary
			dm.max = 20;//
			dm.min = 5;//
			Position pos;//	 Temperary
			pos = checkAndRand();
			EnemyType = new Zombie(dm, pos, 100, 3);
			enemies.push_back(EnemyType);
		}
	}

	Position checkAndRand();
public:
	static Game& get();
	void DrawField();
	void DrawPlayer();
	void DrawEnemies();
	Player* getPlayer();
};

