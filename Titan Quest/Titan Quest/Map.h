#pragma once
#include <vector>
#include "Enums.h"

using namespace std;

class Map
{
	vector<vector<MapCell>> field;

	Map(int width = 40, int height = 40) : width(width), height(height)
	{
		field.resize(height);
		for (int i = 0; i < height; i++)
		{
			field[i].resize(width);
		}
		for (int i = 0; i < height; i++)
		{		
			for (int j = 0; j < width; j++)
			{
				int code = rand() % 10;
				if (code < 8)
					field[i][j] = MapCell::Empty;
				else if (code < 10)
					field[i][j] = MapCell::Wall;
			}
		}
	}
public:
	const int width;
	const int height;
	static Map& get()
	{
		static Map INSTANCE;
		return INSTANCE;
	}
	MapCell getCell(int y, int x)
	{
		if (y >= 0 && y < height && x >= 0 && x < width)
			return field[y][x];
		else
			return MapCell::Wall;
	}
};

