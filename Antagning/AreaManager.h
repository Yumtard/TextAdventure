#pragma once

#include "Gloabals.h"
#include "Tile.h"

class AreaManager
{
public:
	bool Walk(Globals::PlayerInput& input);
	bool MoveInDirection(Globals::PlayerInput& input);
	bool IsShop() const;
	bool IsPlains() const;
	bool IsCrossroads() const;
	bool IsPool() const;
	bool IsTwilight() const;

private:
	int x = 1;
	int y = 1;
	Tile tile;
};