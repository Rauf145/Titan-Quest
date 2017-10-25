#pragma once
#include "Character.h"
#include "Map.h"
#include <Windows.h>

class Player : public Character
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	string Name;
	int MP;
	int level;
	int exp;

public:
	Player() 
	{
		position.x = rand() % 40;
		position.y = rand() % 40;
		while (Map::get().getCell(position.x,position.y) != Empty)
		{
			position.x = rand() % 40;
			position.y = rand() % 40;
		}
		cin >> Name;
		MP = 100;
		level = 0;
		exp = 0;
	}
	//string const getName();
	//void AttackCh(Character &ch)
	//{
	//	cout << endl;
	//}

	// Inherited via Character
	void move(Direction dir) override;

	// Inherited via Character
	void AttackCh(Character & ch) override;
	//void setName(string Name);
};

