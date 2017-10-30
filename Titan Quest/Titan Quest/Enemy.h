#pragma once
#include "Character.h"
#include "Map.h"
class Enemy : public Character
{
protected:
	static int count;
public:
	Enemy(Damage damage, Position position, int HP, int cooldown);
};

