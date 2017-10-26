#include "Player.h"


void Player::move(Direction dir)
{
	SetConsoleCursorPosition(h, { (short)getPosition().x, (short)getPosition().y + 1 });
	cout << " ";
	if (dir == Up && position.y > 0 && Map::get().getCell(position.y - 1,position.x) == Empty)
		position.y--;
	else if (dir == Down && position.y < 39 && Map::get().getCell(position.y + 1, position.x) == Empty)
		position.y++;
	else if (dir == Left && position.x > 0 && Map::get().getCell(position.y, position.x - 1) == Empty)
		position.x--;
	else if (dir == Right && position.x < 39 && Map::get().getCell(position.y, position.x + 1) == Empty)
		position.x++;
}

void Player::AttackCh(Character & ch)
{
	int Left;
	int Right;
	int Up;
	int Down;
	position.y + 1 <= 39 ? Down = position.y + 1 : Down = position.y;
	position.y - 1 >= 0 ? Up = position.y - 1 : Up = position.y;
	position.x + 1 <= 39 ? Right = position.x + 1 : Right = position.x;
	position.x - 1 >= 0 ? Left = position.x - 1 : Left = position.x;
	//for (int i = Up; i <= Down; i++)
	//{
	//	for (int j = Left; j < Right; j++)
	//	{
	//		if ()
	//		{

	//		}
	//	}
	//}
}
