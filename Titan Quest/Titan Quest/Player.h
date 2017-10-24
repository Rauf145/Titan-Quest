#pragma once
#include "Character.h"
#include "Map.h"

class Player : public Character
{
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
	string const getName();
	//void setName(string Name);
};

