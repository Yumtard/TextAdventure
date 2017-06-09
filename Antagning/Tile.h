#pragma once

#include "Gloabals.h"
#include <string>
#include <iostream>

class Tile
{
public:
	enum Type
	{
		CrossRoads, Plains, Twilight, Pool, HeroShop, Empty
	};
	Tile(Type type_in);
	Tile() = default;
	bool CanWalk();
	Type GetTileType() const;

private:
	bool west;
	bool east;
	bool north;
	bool south;
	Type type;
};