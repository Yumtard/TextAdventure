#pragma once

#include "Gloabals.h"
#include <string>
#include <iostream>

class Tile
{
public:
	enum Type
	{
		CrossRoads, Plains, Twilight, Pool, HeroShop
	};

	bool CanWalk(Globals::PlayerInput& input, int x, int y);
	void SetCurrentTile(int x, int y);
	bool IsShop() const;
	bool IsPlains() const;
	bool IsCrossroads() const;
	bool IsPool() const;
	bool IsTwilight() const;

private:
	bool west;
	bool east;
	bool north;
	bool south;
	Type type;
};