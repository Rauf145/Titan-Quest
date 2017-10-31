#include "Zombie.h"

void Zombie::move(Direction dir)
{

	if (dir == Up && position.y > 0 && Map::get().getCell(position.y - 1, position.x) == Empty)
		position.y--;
	else if (dir == Down && position.y < 39 && Map::get().getCell(position.y + 1, position.x) == Empty)
		position.y++;
	else if (dir == Left && position.x > 0 && Map::get().getCell(position.y, position.x - 1) == Empty)
		position.x--;
	else if (dir == Right && position.x < 39 && Map::get().getCell(position.y, position.x + 1) == Empty)
		position.x++;
}

void Zombie::AttackCh(Character & ch)
{
	int randDamage = 0;
	randDamage = rand() % (damage.max - damage.min) + damage.min;
	if (ch.getHP() < randDamage)
		randDamage = ch.getHP();
	ch.setHP(ch.getHP() - randDamage);
	//int left;
	//int right;
	//int up;
	//int down;
	//int checker = 0; //кастыль
	//position.y + 1 <= 39 ? down = position.y + 1 : down = position.y;
	//position.y - 1 >= 0 ? up = position.y - 1 : up = position.y;
	//position.x + 1 <= 39 ? right = position.x + 1 : right = position.x;
	//position.x - 1 >= 0 ? left = position.x - 1 : left = position.x;
	//for (int i = up; i <= down; i++)
	//{
	//	for (int j = left; j < right; j++)
	//	{
	//		if (game::get().getplayer()->position.x == j && game::get().getplayer()->position.y == i)
	//		{
	//			randdamage = rand() % (damage.max - damage.min) + damage.min;
	//			game::get().getplayer()->hp -= randdamage;
	//			checker = 1; //кастыль
	//			break;
	//		}
	//	}
	//	if (checker == 1) //кастыль
	//		break;
	//}
	//state = attack;
}
