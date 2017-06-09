#pragma once

//Gloabal enums with all possible commands and invalid other user input

class Globals
{
public:
	enum PlayerInput
	{
		North,
		West,
		South,
		East,
		Status,
		Inventory,
		Kill,
		Talisman,
		Charm,
		Invalid
	};
};