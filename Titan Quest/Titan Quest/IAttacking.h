#pragma once
#include "Enums.h"
class IAttacking
{
protected:
	Damage damage;
public:
	IAttacking();
	virtual void AttackCh(Character &ch) = 0;
};

