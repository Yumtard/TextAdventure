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
	bool CanWalk();
	Type GetTileType() const;

private:
	Type type;
};