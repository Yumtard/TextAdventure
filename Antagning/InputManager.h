#pragma once

#include "Gloabals.h"
#include <string>

class InputManager
{
public:
	Globals::PlayerInput GetInput(std::string command);
};