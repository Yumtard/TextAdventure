#pragma once

#include "Gloabals.h"
#include "Tile.h"

class AreaManager
{
public:
	AreaManager();
	bool Walk(Globals::PlayerInput& input);
	bool MoveInDirection(Globals::PlayerInput& input);
	Tile::Type CurrentTile() const;

private:
	int x = 1;
	int y = 1;
	Tile tiles[3][3];
};