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
}

void Game::DrawEnemies()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		SetConsoleCursorPosition(h, {(short)enemies[i]->getPosition().x, (short)enemies[i]->getPosition().y + 1 });
		cout << "*";
	}

}

Player* Game::getPlayer()
{
	return player;
}
