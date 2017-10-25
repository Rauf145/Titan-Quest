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
	cout << endl;
}
