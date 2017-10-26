#include "Game.h"

Game & Game::get()
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

Player* Game::getPlayer()
{
	return player;
}
