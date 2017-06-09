#include "Tile.h"

Tile::Tile(Type type_in)
	:
	type(type_in)
{
}

//Gets called in AreaManager
//If the type of the tiles enum is not Empty, we can walk there and the function returns true
//else we can't and the function returns false
bool Tile::CanWalk()
{
	if (type != Empty)
	{
		return true;
	}
	return false;
}

//returns the type of the tile
Tile::Type Tile::GetTileType() const
{
	return type;
}



