#include "AreaManager.h"

AreaManager::AreaManager()
{
	tiles[0][0] = { Tile(Tile::Type::Empty) };
	tiles[1][0] = { Tile(Tile::Type::Twilight) };
	tiles[2][0] = { Tile(Tile::Type::Empty) };
	tiles[0][1] = { Tile(Tile::Type::Plains) };
	tiles[1][1] = { Tile(Tile::Type::CrossRoads) };
	tiles[2][1] = { Tile(Tile::Type::HeroShop) };
	tiles[0][2] = { Tile(Tile::Type::Empty) };
	tiles[1][2] = { Tile(Tile::Type::Pool) };
	tiles[2][2] = { Tile(Tile::Type::Empty) };
}

bool AreaManager::Walk(Globals::PlayerInput & input)
{
	if (MoveInDirection(input))
	{
		return true;
	}

	return false;
}

bool AreaManager::MoveInDirection(Globals::PlayerInput & input)
{
	if (input == Globals::West)
	{
		if (tiles[x - 1][y].CanWalk())
		{
			x--;
			return true;
		}
		else
		{
			std::cout << "You can't go west here" << std::endl;
		}
	}

	else if (input == Globals::East)
	{
		if (tiles[x + 1][y].CanWalk())
		{
			x++;
			return true;
		}
		else
		{
			std::cout << "You can't go east here" << std::endl;
		}
	}

	else if (input == Globals::North)
	{
		if (tiles[x][y - 1].CanWalk())
		{
			y--;
			return true;
		}
		else
		{
			std::cout << "You can't go north here" << std::endl;
		}
	}

	else if (input == Globals::South)
	{
		if (tiles[x][y + 1].CanWalk())
		{
			y++;
			return true;
		}
		else
		{
			std::cout << "You can't go south here" << std::endl;
		}
	}

	return false;
}

Tile::Type AreaManager::CurrentTile() const
{
	return tiles[x][y].GetTileType();
}
