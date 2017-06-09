#include "AreaManager.h"

//Inits the 2d array of Tiles setting their types
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

//Gets called in World.cpp
//If it returns false we know the command wasn't a direction
bool AreaManager::Walk(Globals::PlayerInput & input)
{
	if (MoveInDirection(input))
	{
		return true;
	}

	return false;
}

//Checks if the command is a direction
//If yes, then check if we can move to that tile, if we can then do it, if we can't we get a message.
//If not a direction, return false
bool AreaManager::MoveInDirection(Globals::PlayerInput & input)
{
	if (input == Globals::West)
	{
		if (tiles[x - 1][y].CanWalk() && x > 0) //if x is smaller than 1, we can't move west since that's outside of the array
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
		if (tiles[x + 1][y].CanWalk() && x < 2)
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
		if (tiles[x][y - 1].CanWalk() && y > 0)
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
		if (tiles[x][y + 1].CanWalk() && y < 2)
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

//Returns the current tile based on x and y position
Tile::Type AreaManager::CurrentTile() const
{
	return tiles[x][y].GetTileType();
}
