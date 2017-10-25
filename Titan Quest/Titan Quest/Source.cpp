#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "Player.h"
#include <conio.h>
#include <Windows.h>

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
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//Game initialization
	int button;
	Player player;
	Map::get();
	for (int i = 0; i < Map::get().height; i++)
	{		
		for (int j = 0; j < Map::get().width; j++)
		{
			if (i == player.getPosition().y && j == player.getPosition().x)
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
	while (true)
	{
		SetConsoleCursorPosition(h, {(short) player.getPosition().x, (short)player.getPosition().y + 1});
		cout << "@";
		button = getch();
		player.move(Direction(button));
	}
	//Game loop
	//while (true)
	//{
		//Input handling

		//Game logic

		//Drawing
	//}
}