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
	void LevelReader();

private:
	int x = 1;
	int y = 1;
	static constexpr int maxLevelWidth = 3;
	static constexpr int maxLevelHeight = 3;
	static constexpr int minLevelWidth = 0;
	static constexpr int minLevelHeight = 0;
	Tile tiles[maxLevelWidth][maxLevelHeight];
	char level[maxLevelHeight][maxLevelWidth];
};