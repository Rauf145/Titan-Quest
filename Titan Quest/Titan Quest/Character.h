#pragma once
#include "GameObject.h"
#include "IMovable.h"
#include "IAttacking.h"
#include "Enums.h"

class Character : public GameObject, public IMovable, public IAttacking
{
	protected:
	int HP;
	int STATE;
public:
	Character()
	{			
		HP = 100;
		STATE = State::Idle;
	}
	/*Character(int HP)
	{
		HP = 100;
		STATE = State::Idle;
	}*/
	int getHP();
	void setHP(int HP);
	int getSTATE();
	void setSTATE(int STATE);
};

