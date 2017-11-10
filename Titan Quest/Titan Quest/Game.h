#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Zombie.h"
class Game
{
	sf::RenderWindow window;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //*
	Player* player;
	vector<GameObject*> staticObjects;
	vector<Enemy*> enemies;
	sf::Texture EmptyTexture;
	sf::Texture WallTexture;
	sf::Texture PlayerTexture;
	sf::RectangleShape EmptyRect;
	sf::RectangleShape WallRect;
	sf::RectangleShape PlayerRect;

	Game()
	{
		Enemy *EnemyType;
		Map::get();
		player = new Player;
		window.create(sf::VideoMode(800, 800), "Titan Quest");
		EmptyTexture.loadFromFile("grass.png");
		WallTexture.loadFromFile("wall.png");
		PlayerTexture.loadFromFile("player.png");
		EmptyRect.setSize(sf::Vector2f(20, 20));
		WallRect.setSize(sf::Vector2f(20, 20));
		PlayerRect.setSize(sf::Vector2f(20, 20));
		EmptyRect.setTexture(&EmptyTexture);
		WallRect.setTexture(&WallTexture);
		PlayerRect.setTexture(&PlayerTexture);
		for (int i = 0; i < 10; i++)
		{
			Damage dm;//	 Temperary
			Position pos;//	 Temperary
			dm.max = 10;//
			dm.min = 5;//
			pos = checkAndRand();
			EnemyType = new Zombie(dm, pos, 100, 3);
			enemies.push_back(EnemyType);
		}
	}

	Position checkAndRand();
public:
	static Game& get();
	sf::RenderWindow& GetWindow();
	void DrawField();
	void DrawPlayer();
	void DrawEnemies();
	void EnemyMove();
	Player* getPlayer();
	void ScanArea();
};

