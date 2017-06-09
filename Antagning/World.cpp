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
	HandleArea(areamanager.CurrentTile());
	while (hero.IsAlive() && !gameIsWon)
	{
		std::getline(std::cin, command);
		input = inputManager.GetInput(command);

		if (areamanager.Walk(input))
		{
			HandleArea(areamanager.CurrentTile());
		}
		else
		{
			switch (input)
			{
			case Globals::Status:
				hero.Status();
				break;

			case Globals::Charm:
				if (areamanager.CurrentTile() == Tile::HeroShop)
				{
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
				}

				else
				{
					std::cout << "Visit Hero's Shop to purchase items." << std::endl;
				}

				break;

			case Globals::Inventory:
				if (areamanager.CurrentTile() == Tile::HeroShop)
				{
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
				}

				else
				{
					std::cout << "Visit Hero's shop to see what's available for purchase." << std::endl;
				}
				break;

			case Globals::Kill:
				if (areamanager.CurrentTile() == Tile::Plains)
				{
					hero.KillMonster(charmMultiplier);
				}
				else
				{
					std::cout << "There are no monsters here for you to kill." << std::endl;
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

			case Globals::Invalid:
				InvalidCommand(command);
				break;
			}
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

void World::InvalidCommand(std::string cmnd)
{
	std::cout << "Sorry, \"" << cmnd << "\" is not a valid command" << std::endl;
}

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
		break;
	}
}


