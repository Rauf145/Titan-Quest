#pragma once
#include "GameObject.h"
#include "IMovable.h"
#include "IAttacking.h"

class Character : public GameObject, public IMovable, public IAttacking
{
	int HP;
	int MP;
	int STATE;
public:
	Character()
	{
		HP = 100;
		MP = 100;
		STATE = State::Idle;
	}
};

