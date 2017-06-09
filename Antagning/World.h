#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Hero.h"
#include "Gloabals.h"
#include "InputManager.h"
#include "AreaManager.h"
#include "Tile.h"

class World
{
public:
	World();
	void Update();
	void InvalidCommand(std::string cmnd);
	void CrossRoadMsg();
	void PlainsMsg();
	void ShopMsg();
	void PoolMsg();
	void TwilightMsg();

private:
	Hero hero;
	std::string command;
	std::vector<std::string> inventory;
	static constexpr int talismanPrice = 100;
	static constexpr int charmPrice = 20;
	bool charmIsObtained = false;
	bool talismanIsObtained = false;
	int charmMultiplier = 1;
	bool gameIsWon = false;
	InputManager inputManager;
	Globals::PlayerInput input;
	AreaManager areamanager;
};