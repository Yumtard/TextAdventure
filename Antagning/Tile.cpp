#include "Tile.h"

bool Tile::CanWalk(Globals::PlayerInput & input, int x, int y)
{
	SetCurrentTile(x, y);

	switch(type)
	{
	case CrossRoads:
		west = true;
		north = true;
		south = true;
		east = true;
		break;

	case Plains:
		west = false;
		north = false;
		south = false;
		east = true;
		break;

	case Pool:
		west = false;
		north = true;
		south = false;
		east = false;
		break;

	case HeroShop:
		west = true;
		north = false;
		south = false;
		east = false;
		break;

	case Twilight:
		west = false;
		north = false;
		south = false;
		east = false;
		
		break;
	}

	switch (input)
	{
	case Globals::West:
		return west;
		break;

	case Globals::East:
		return east;
		break;

	case Globals::South:
		return south;
		break;

	case Globals::North:
		return north;
		break;
	}
}

void Tile::SetCurrentTile(int x, int y)
{
	if (x == 1 && y == 1)
		type = CrossRoads;

	else if (x == 0 && y == 1)
		type = Plains;

	else if (x == 2 && y == 1)
		type = HeroShop;

	else if (x == 1 && y == 0)
		type = Pool;

	else if (x == 1 && y == 2)
		type = Twilight;
}

bool Tile::IsShop() const
{
	if (type == HeroShop)
	{
		return true;
	}
	return false;
}

bool Tile::IsPlains() const
{
	if (type == Plains)
	{
		return true;
	}
	return false;
}

bool Tile::IsCrossroads() const
{
	if (type == CrossRoads)
	{
		return true;
	}
	return false;
}

bool Tile::IsPool() const
{
	if (type == Pool)
	{
		return true;
	}
	return false;
}

bool Tile::IsTwilight() const
{
	if (type == Twilight)
	{
		return true;
	}
	return false;
}


