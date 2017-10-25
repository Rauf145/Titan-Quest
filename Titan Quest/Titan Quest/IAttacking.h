#pragma once
#include "Enums.h"

class Character;

class IAttacking
{
protected:
	Damage damage;
	int cooldown;
public:
	virtual void AttackCh(Character &ch) = 0;
};

