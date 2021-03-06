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
	CrossRoadMsg();
	while (hero.IsAlive() && !gameIsWon)
	{
		PlayGame();

		if (location == Pool)
		{
			hero.Heal();
		}
	}
		
	if (!hero.IsAlive())
	{
		std::cout << "You got killed. Game over." << std::endl;
	}
	if (gameIsWon)
	{
		std::cout << "Congratulations! You've completed the game." << std::endl;
	}
}

void World::PlayGame()
{
	if (hero.IsAlive())
	{
		std::getline(std::cin, command);

		if (command == "status")
		{
			hero.Status();
		}

		else if (command == "north")
		{
			switch (location)
			{
			case Crossroads:
				location = TwilightCave;
				TwilightMsg();
				break;

			case Pool:
				location = Crossroads;
				CrossRoadMsg();
				break;

			default:
				std::cout << "Can't go north." << std::endl;
			}
		}

		else if (command == "west")
		{
			switch (location)
			{
			case Crossroads:
				location = PlainsOfGrinding;
				PlainsMsg();
				break;

			case Shop:
				location = Crossroads;
				CrossRoadMsg();
				break;

			default:
				std::cout << "Can't go west." << std::endl;
			}
		}

		else if (command == "south")
		{
			switch (location)
			{
			case Crossroads:
				location = Pool;
				PoolMsg();
				break;

			default:
				std::cout << "Can't go south." << std::endl;
			}
		}

		else if (command == "east")
		{
			switch (location)
			{
			case Crossroads:
				location = Shop;
				ShopMsg();
				break;

			case PlainsOfGrinding:
				location = Crossroads;
				CrossRoadMsg();
				break;

			default:
				std::cout << "Can't go east." << std::endl;
			}
		}

		else if (command == "kill monster")
		{
			switch (location)
			{
			case PlainsOfGrinding:
				hero.KillMonster(charmMultiplier);
				
				break;

			default:
				std::cout << "There are no monsters here." << std::endl;
			}
		}

		else if (command == "look inventory")
		{
			switch (location)
			{
			case Shop:
				if (inventory.size() == 0)
				{
					std::cout << "We're all out of items to buy." << std::endl;
				}

				else
				{
					std::cout << "The shopkeeper has the following in stock:" << std::endl;

					for (int i = 0; i < inventory.size(); ++i)
					{
						std::cout << "- " << inventory[i] << std::endl;
					}
				}

				break;

			default:
				std::cout << "Go to Hero's Shop to look at the inventory." << std::endl;
			}
		}

		else if (command == "buy charm")
		{
			switch (location)
			{
			case Shop:
				if (!charmIsObtained)
				{
					if (hero.BuyCharm(charmPrice))
					{
						std::cout << "You have bought the Charm of Capitalism for 20 gold" << std::endl;
						charmIsObtained = true;
						charmMultiplier = 10;
						inventory[0] = inventory.back();
						inventory.pop_back();
					}
				}
				else
				{
					std::cout << "You have already bought this item." << std::endl;
				}

				break;

			default:
				std::cout << "Visit Hero's Shop to purchase items." << std::endl;
			}
		}

		else if (command == "buy talisman")
		{
			switch (location)
			{
			case Shop:
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

				break;

			default:
				std::cout << "Visit Hero's Shop to purchase items." << std::endl;
			}
		}

		else
		{
			InvalidCommand(command);
		}
	}
}

void World::InvalidCommand(std::string cmnd)
{
	std::cout << "Sorry, \"" << cmnd << "\" is not a valid command" << std::endl;
}

void World::CrossRoadMsg()
{
	std::cout << "You are standing at the Crossroads. The sun is shining down through the foliage." << std::endl;
}

void World::PlainsMsg()
{
	std::cout << "You are standing on the Plains of Grinding. Monsters are lined up in a queue, staring at you." << std::endl;
}

void World::ShopMsg()
{
	std::cout << "You entered the conveniently places Hero's Shop. A shopkeeper is staring at you." << std::endl;
}

void World::PoolMsg()
{
	std::cout << "You enter the Pool of Rejuvination. You feel power surge through you!" << std::endl;
}

void World::TwilightMsg()
{
	std::cout << "You have entered the Twlight Cave. A horrifying beast emerges from the shadows." << std::endl;

	if (!talismanIsObtained)
	{
		std::cout << "The beast is too powerful." << std::endl;
		hero.KillHero();
	}
	else
	{
		std::cout << "You pull out the Talisman of Truth" << std::endl;
		std::cout << "It fills you with immense power and you effortlessly kill the beast." << std::endl;
		gameIsWon = true;
	}
}


