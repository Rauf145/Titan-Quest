#pragma once
#include "Enums.h"

class IMovable
{
	Direction direction;
public:
	virtual void move(Direction dir) = 0;
	//IMovable();
	//~IMovable();
};

