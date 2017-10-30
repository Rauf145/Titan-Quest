#pragma once
enum Direction { Up = 'w', Down = 's', Left = 'a', Right = 'd' };
enum State { Idle, Attack, Defend, Shoot, Dead };
enum MapCell { Empty, Wall};
struct Position { int x, y; };
struct Damage { int min, max; };