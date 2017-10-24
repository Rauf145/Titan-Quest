#pragma once
#include "Enums.h"
#include <iostream>
#include <string>

using namespace std;

class GameObject
{
	Position position;
public:
	GameObject(int x, int y);
	GameObject() {};
	Position getPosition();
	void setPosition(int x, int y);
};

