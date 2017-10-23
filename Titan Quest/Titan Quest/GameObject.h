#pragma once

enum State { Idle, Attack, Defend, Shoot, Dead };
enum MapCell { Empty, Wall, Hole };
struct Position { int x, y; };
struct Damage { int min, max; };

class GameObject
{
	Position position;
public:
	GameObject(int x, int y);
	Position getPosition();
	void setPosition(int x, int y);
};

