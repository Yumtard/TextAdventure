#include "InputManager.h"

//User input gets passed to the function in a string
//Returns a Global enum based on the contents of the string

Globals::PlayerInput InputManager::GetInput(std::string command)
{
	if (command == "west" || command == "West")
		return Globals::PlayerInput::West;

	else if (command == "north" || command == "North")
		return Globals::PlayerInput::North;

	else if (command == "south" || command == "South")
		return Globals::PlayerInput::South;

	else if (command == "east" || command == "East")
		return Globals::PlayerInput::East;

	else if (command == "status" || command == "Status")
		return Globals::PlayerInput::Status;

	else if (command == "look inventory" || command == "Look inventory")
		return Globals::PlayerInput::Inventory;

	else if (command == "kill monster" || command == "Kill monster")
		return Globals::PlayerInput::Kill;

	else if (command == "buy talisman" || command == "Buy talisman")
		return Globals::PlayerInput::Talisman;

	else if (command == "buy charm" || command == "Buy charm")
		return Globals::PlayerInput::Charm;

	else
		return Globals::PlayerInput::Invalid;
}
