#pragma once
#include "Enemy.h"

class Zombie : public Enemy
{
public:
	Zombie(Damage damage, Position position, int HP, int cooldown) : Enemy(damage, position, HP, cooldown){}
	void move(Direction dir);
	void AttackCh(Character &ch);
	//void ScanArea();
};

