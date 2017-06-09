#include "AreaManager.h"
#include <fstream>

//load level
AreaManager::AreaManager()
{
	LevelReader();
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
		const int newPosX = x - 1;
		if (tiles[newPosX][y].CanWalk() && newPosX >= minLevelWidth) 
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
		const int newPosX = x + 1;
		if (tiles[newPosX][y].CanWalk() && newPosX < maxLevelWidth)
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
		const int newPosY = y - 1;
		if (tiles[x][newPosY].CanWalk() && newPosY >= minLevelHeight)
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
		const int newPosY = y + 1;
		if (tiles[x][newPosY].CanWalk() && newPosY < maxLevelHeight)
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

//reads the level from a text file
void AreaManager::LevelReader()
{
	std::ifstream read;
	read.open("level.txt");

	//loop through the with and height of the level and store the
	//information in a 2d char array "level"
	for (int i = minLevelHeight; i < maxLevelHeight; ++i)
	{
		for (int j = minLevelWidth; j < maxLevelWidth; ++j)
		{
			read >> level[i][j];
		}
	}
	read.close();

	//loop through the 2d char array and init tiles
	//Tile type is determined based on what char it is
	for (int i = minLevelHeight; i < maxLevelHeight; ++i)
	{
		for (int j = minLevelWidth; j < maxLevelWidth; ++j)
		{
			switch (level[i][j])
			{
			case 'C':
				tiles[j][i] = { Tile(Tile::Type::CrossRoads) };
				break;

			case 'T':
				tiles[j][i] = { Tile(Tile::Type::Twilight) };
				break;

			case 'P':
				tiles[j][i] = { Tile(Tile::Type::Pool) };
				break;

			case 'G':
				tiles[j][i] = { Tile(Tile::Type::Plains) };
				break;

			case 'S':
				tiles[j][i] = { Tile(Tile::Type::HeroShop) };
				break;

			case 'X':
				tiles[j][i] = { Tile(Tile::Type::Empty) };
				break;
			}
		}
	}
}
