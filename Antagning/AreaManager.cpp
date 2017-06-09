#include "AreaManager.h"

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
		if (tile.CanWalk(input, x, y))
		{
			x--;
			tile.SetCurrentTile(x, y);
			return true;
		}
		else
		{
			std::cout << "You can't go west here" << std::endl;
		}
	}

	else if (input == Globals::East)
	{
		if (tile.CanWalk(input, x, y))
		{
			x++;
			tile.SetCurrentTile(x, y);
			return true;
		}
		else
		{
			std::cout << "You can't go east here" << std::endl;
		}
	}

	else if (input == Globals::North)
	{
		if (tile.CanWalk(input, x, y))
		{
			y++;
			tile.SetCurrentTile(x, y);
			return true;
		}
		else
		{
			std::cout << "You can't go north here" << std::endl;
		}
	}

	else if (input == Globals::South)
	{
		if (tile.CanWalk(input, x, y))
		{
			y--;
			tile.SetCurrentTile(x, y);
			return true;
		}
		else
		{
			std::cout << "You can't go south here" << std::endl;
		}
	}

	return false;
}

bool AreaManager::IsShop() const
{
	return tile.IsShop();
}

bool AreaManager::IsPlains() const
{
	return tile.IsPlains();
}

bool AreaManager::IsCrossroads() const
{
	return tile.IsCrossroads();
}

bool AreaManager::IsPool() const
{
	return tile.IsPool();
}

bool AreaManager::IsTwilight() const
{
	return tile.IsTwilight();
}
