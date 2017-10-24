#pragma once
enum Direction { Up, Down, Left, Right };
enum State { Idle, Attack, Defend, Shoot, Dead };
enum MapCell { Empty, Wall, Hole };
struct Position { int x, y; };
struct Damage { int min, max; };