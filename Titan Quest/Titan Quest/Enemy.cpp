#include "Enemy.h"

Enemy::Enemy(Damage damage, Position position, int HP, int cooldown) 
{
	/*	position.x = rand() % 40;
	position.y = rand() % 40;
	while (Map::get().getCell(position.x, position.y) != Empty)
	{
	position.x = rand() % 40;
	position.y = rand() % 40;
	}*/
	this->position.x = position.x;
	this->position.y = position.y;
	this->damage.min = damage.min;
	this->damage.max = damage.max;
	this->HP = HP;
	STATE = Idle;
	this->cooldown = cooldown;
	count++;
}

int Enemy::count = 0;