#include "Tile.h"

Tile::Tile(Type type_in)
	:
	type(type_in)
{
}

bool Tile::CanWalk()
{
	if (type != Empty)
	{
		return true;
	}
	return false;
}

Tile::Type Tile::GetTileType() const
{
	return type;
}



