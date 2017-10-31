#pragma once
#include "Enums.h"
#include <iostream>
#include <string>
#include <time.h>
	
using namespace std;

class GameObject
{
protected:
	Position position;
public:
	GameObject(int x, int y);
	GameObject() {};
	Position getPosition();
	void setPosition(int x, int y);
};

