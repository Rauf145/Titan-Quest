#include "GameObject.h"



GameObject::GameObject(int x, int y)
{
	position.x = x;
	position.y = y;
}

Position GameObject::getPosition()
{
	return position;
}

void GameObject::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
