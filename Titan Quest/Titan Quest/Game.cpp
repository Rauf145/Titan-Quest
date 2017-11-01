#include "Game.h"

Position Game::checkAndRand()
{
	int checker = 0; // Kastil
	Position position;
	position.x = rand() % 40;
	position.y = rand() % 40;
	while (checker == 0)
	{
		checker = 1; // Kastil
		position.x = rand() % 40;
		position.y = rand() % 40;
		for (int i = 0; i < enemies.size(); i++)
		{
			if (position.x == enemies[i]->getPosition().x && position.y == enemies[i]->getPosition().y)// Kastil
			{
				checker = 0;
				break;
			}
		}
		if (Map::get().getCell(position.y, position.x) == Wall) // Kastil
			checker = 0;
	}
	return position;
}

Game& Game::get()
{
	static Game game;
	return game;
}

void Game::DrawField()
{
	for (int i = 0; i < Map::get().height; i++)
	{
		for (int j = 0; j < Map::get().width; j++)
		{
			if (i == player->getPosition().y && j == player->getPosition().x)
			{
				cout << "@";
			}
			else if (Map::get().getCell(i, j) == Wall)
			{
				cout << char(219);
			}
			else
				cout << " ";
			//cout << Map::get().getCell(i, j);
		}
		cout << endl;
	}
}

void Game::DrawPlayer()
{
	SetConsoleCursorPosition(h, { (short)player->getPosition().x, (short)player->getPosition().y + 1 });
	cout << "@";
	SetConsoleCursorPosition(h, { (short) 0, (short)41});
	cout << "   ";
	SetConsoleCursorPosition(h, { (short)0, (short)41 });
	cout << player->getHP();
}

void Game::DrawEnemies()
{
	int Dir;
	for (int i = 0; i < enemies.size(); i++)
	{
		SetConsoleCursorPosition(h, {(short)enemies[i]->getPosition().x, (short)enemies[i]->getPosition().y + 1 });
		cout << "*";
	}

}

void Game::EnemyMove()
{
	int randDir;
	for (int i = 0; i < enemies.size(); i++)
	{
		SetConsoleCursorPosition(h, { (short)enemies[i]->getPosition().x, (short)enemies[i]->getPosition().y + 1 }); //
		cout << " "; //
		randDir = rand() % 4;
		if (randDir == 0)
			enemies[i]->move(Up);
		else if (randDir == 1)
			enemies[i]->move(Down);
		else if (randDir == 2)
			enemies[i]->move(Left);
		else
			enemies[i]->move(Right);
	}
}

Player* Game::getPlayer()
{
	return player;
}

void Game::ScanArea()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		int left;
		int right;
		int up;
		int down;
		int checker = 0; //кастыль
		enemies[i]->getPosition().y + 1 <= 39 ? down = enemies[i]->getPosition().y + 1 : down = enemies[i]->getPosition().y;
		enemies[i]->getPosition().y - 1 >= 0 ? up = enemies[i]->getPosition().y - 1 : up = enemies[i]->getPosition().y;
		enemies[i]->getPosition().x + 1 <= 39 ? right = enemies[i]->getPosition().x + 1 : right = enemies[i]->getPosition().x;
		enemies[i]->getPosition().x - 1 >= 0 ? left = enemies[i]->getPosition().x - 1 : left = enemies[i]->getPosition().x;
		for (int j = up; j <= down; j++)
		{
			for (int k = left; k <= right; k++)
			{
				if (player->getPosition().x == k && player->getPosition().y == j)
				{
					checker = 1; //кастыль
					break;
				}
			}
			if (checker == 1) //кастыль
				break;
		}
		if (checker == 1)
			enemies[i]->AttackCh(*player);
	}
}
