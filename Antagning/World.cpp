#include "World.h"


World::World()
	:
	hero(100, 0)
{
	inventory.push_back("Charm of Capitalism (20 gold)");
	inventory.push_back("Talisman of Truth (100 gold)");
}

void World::Update()
{
	//start off by handling the current area
	HandleArea(areamanager.CurrentTile());

	//loops while hero has health and the game isn't won
	while (hero.IsAlive() && !gameIsWon)
	{

		//Get user input
		std::string command;
		std::getline(std::cin, command);
		Globals::PlayerInput input = inputManager.GetInput(command);

		//if the command was a direction
		//if it is then if possible we move to the tile in that direction
		if (areamanager.Walk(input))
		{
			//Gives the user a message and performs potential tasks based on which tile we got moved to
			HandleArea(areamanager.CurrentTile());
		}
		else
		{
			//If the command wasn't a direction, this function handles the input instead
			NonDirectionInput(input, command);
		}
	}
	
	//Displays a message if hero runs out of health
	if (!hero.IsAlive())
	{
		std::cout << "You got killed. Game over." << std::endl;
	}
	//Displays a message if the game is won
	if (gameIsWon)
	{
		std::cout << "Congratulations! You've completed the game." << std::endl;
	}
}

//Displays a message if the user input is invalid
//Shows the user what invalid input was typed
void World::InvalidCommand(std::string cmnd)
{
	std::cout << "Sorry, \"" << cmnd << "\" is not a valid command" << std::endl;
}

//Does the tasks connected to the current tile
void World::HandleArea(Tile::Type tileType)
{
	switch (tileType)
	{
	case Tile::CrossRoads:
		std::cout << "You are standing at the Crossroads. The sun is shining down through the foliage." << std::endl;
		break;

	case Tile::Plains:
		std::cout << "You are standing on the Plains of Grinding. Monsters are lined up in a queue, staring at you." << std::endl;
		break;

	case Tile::HeroShop:
		std::cout << "You entered the conveniently places Hero's Shop. A shopkeeper is staring at you." << std::endl;
		break;

	case Tile::Pool:
		std::cout << "You enter the Pool of Rejuvination. You feel power surge through you!" << std::endl;
		hero.Heal();
		break;

	case Tile::Twilight:
		std::cout << "You have entered the Twlight Cave. A horrifying beast emerges from the shadows." << std::endl;

		//Kills hero if he doesn't have the talisman
		if (!talismanIsObtained)
		{
			std::cout << "The beast is too powerful." << std::endl;
			hero.KillHero();
		}

		//Wins the game if he does have the talisman
		else
		{
			std::cout << "You pull out the Talisman of Truth" << std::endl;
			std::cout << "It fills you with immense power and you effortlessly kill the beast." << std::endl;
			gameIsWon = true;
		}
		break;
	}
}

//Handles input thats not a direction
void World::NonDirectionInput(Globals::PlayerInput _input, std::string cmnd)
{
	switch (_input)
	{
	case Globals::Status:
		hero.Status();
		break;

	case Globals::Charm:
		if (areamanager.CurrentTile() == Tile::HeroShop)
		{
			if (!charmIsObtained)
			{
				//if hero is in the shop, doesn't already have the charm and can afford it then he buys it
				if (hero.BuyCharm(charmPrice))
				{
					std::cout << "You have bought the Charm of Capitalism for 20 gold" << std::endl;
					charmIsObtained = true; //now hero can no longer buy the charm
					charmMultiplier = 10;  //increases from 1 to 10. Gets multiplied with the gold reward when killing monsters
					inventory[0] = inventory.back(); //Sets the first element to the same value as the last element
					inventory.pop_back(); //deletes the last element
				}
			}
			else
			{
				std::cout << "You have already bought this item." << std::endl;
			}
		}

		//if hero is on another tile than shop
		else
		{
			std::cout << "Visit Hero's Shop to purchase items." << std::endl;
		}

		break;

	case Globals::Inventory:
		if (areamanager.CurrentTile() == Tile::HeroShop)
		{
			//when all items have been bought
			if (inventory.size() == 0)
			{
				std::cout << "We're all out of items to buy." << std::endl;
			}

			//Displays items for sale
			else
			{
				std::cout << "The shopkeeper has the following in stock:" << std::endl;

				for (int i = 0; i < inventory.size(); ++i)
				{
					std::cout << "- " << inventory[i] << std::endl;
				}
			}
		}

		//If hero is on wrong tile
		else
		{
			std::cout << "Visit Hero's shop to see what's available for purchase." << std::endl;
		}
		break;

	case Globals::Kill:
		if (areamanager.CurrentTile() == Tile::Plains)
		{
			hero.KillMonster(charmMultiplier); //multiplies with 1 or 10 depending if hero has the charm
		}
		else
		{
			std::cout << "There are no monsters here for you to kill." << std::endl; //if hero is on wrong tile
		}
		break;

	case Globals::Talisman:
		if (areamanager.CurrentTile() == Tile::HeroShop)
		{
			if (!talismanIsObtained)
			{
				if (hero.BuyTalisman(talismanPrice))
				{
					std::cout << "You have bought the Talisman of Truth for 100 gold" << std::endl;
					talismanIsObtained = true;
					inventory.pop_back();
				}
			}
			else
			{
				std::cout << "You have already bought this item." << std::endl;
			}
		}

		else
		{
			std::cout << "Visit Hero's Shop to purchase items." << std::endl;
		}
		break;

		//For any input that is not a command used anywhere in this game
	case Globals::Invalid:
		InvalidCommand(cmnd);
		break;
	}
}


