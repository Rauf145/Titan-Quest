﻿#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "Player.h"
#include <conio.h>
#include <Windows.h>
#include "Game.h"

//using namespace std;
//
//enum Direction { Up, Down, Left, Right };
//enum State { Idle, Attack, Defend, Shoot, Dead };
//enum MapCell { Empty, Wall, Hole };
//struct Position { int x, y; };
//struct Damage { int min, max; };
//
//class Character;
//
//class IMovable
//{
//	Direction direction;
//public:
//	virtual void move(Direction dir) = 0;
//};
//
//class IAttacking
//{
//	Damage damage;
//	int cooldown;
//public:
//	virtual void attack(Character &target) = 0;
//	virtual void shoot(Character &target) = 0;
//};
//
//class IInteractive
//{
//public:
//	virtual void interaction(Character &target) = 0; //typeid Player
//};
//
//class GameObject
//{
//	Position position;
//};
//
//class Coin : public GameObject, public IInteractive
//{
//	virtual void interaction(Character & target) override;
//};
//
//class Trap : public GameObject, public IInteractive
//{
//	virtual void interaction(Character & target) override;
//};
//
//class Character : public GameObject, public IAttacking, public IMovable
//{
//	int hp;
//	State state;
//
//public:
//	virtual void attack(Character &target) override;
//	virtual void shoot(Character &target) override;
//	virtual void move(Direction dir) override;
//};
//
//class Player : public Character
//{
//	string name;
//	int exp;
//	int level;
//	int strength;
//	int endurance;
//	int dexterity;
//};
//
//class Enemy : public Character
//{
//	static int count;
//public:
//	virtual void scanMap() = 0;
//};
//
//class Zombie : public Enemy
//{
//
//};
//
//class Skeleton : public Enemy
//{
//
//};
//
//class Map
//{
//	MapCell field[50][50];
//public:
//	MapCell getCell(int x, int y);
//};
//
///*
//Files
//const, final, override
//smart pointers
//*/
//
//
//class Game
//{
//	Map& map;
//	Player& player;
//	vector<GameObject> staticObjects;
//	vector<Enemy> enemies;
//};
//
void main()
{
	//Game initialization
	Game::get().DrawField();
	int button;
	while (true)
	{
		Game::get().DrawPlayer();
		Game::get().DrawEnemies();
		button = getch();
		Game::get().getPlayer()->move(Direction(button));
		//player.move(Direction(button));
	}
	//Game loop
	//while (true)
	//{
		//Input handling

		//Game logic

		//Drawing
	//}
}
//#include <SFML/Graphics.hpp>
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//
//	return 0;
//}