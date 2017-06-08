#include "Hero.h"

Hero::Hero(int health_in, int gold_in)
	:
	health(health_in),
	gold(gold_in),
	rng(std::random_device()())
{
}

void Hero::Heal()
{
	health = maxHealth;
}

void Hero::AddGold(int amount)
{
	gold += amount;
}

void Hero::Status() const
{
	std::cout << "Health: " << health << "/" << maxHealth << std::endl;
	std::cout << "Gold: " << gold << std::endl;
	std::cout << "Items: ";

	if (items.size() == 0)
	{
		std::cout << "none";
	}
	else
	{
		for (int i = 0; i < items.size(); ++i)
		{
			std::cout << items[i] << " ";
		}
	}
	
	std::cout << std::endl;
}

bool Hero::IsAlive() const
{
	return isAlive;
}

int Hero::MaxHealth() const
{
	return maxHealth;
}

void Hero::KillMonster(int charmMultiplier)
{
	std::uniform_int_distribution<int> randomDmg(0, 20);
	std::uniform_int_distribution<int> randomReward(1, 10);
	damage = randomDmg(rng);
	reward = randomReward(rng) * charmMultiplier;
	health -= damage;
	gold += reward;

	if (health <= 0)
	{
		isAlive = false;
	}

	if (isAlive)
	{
		std::cout << "You kill the monster without mercy. Mercilessly." << std::endl;
		std::cout << "You take " << damage << " damage! You recieve " << reward << " gold." << std::endl;
	}
}

bool Hero::BuyCharm(int price)
{
	if (gold < price)
	{
		std::cout << "Sorry, the Charm of Capitalism costs " << price << " gold. You only have " << gold << " gold." << std::endl;
		return false;
	}
	else
	{
		items.push_back("Charm of Capitalism");
		gold -= price;
		return true;
	}
}

bool Hero::BuyTalisman(int price)
{
	if (gold < price)
	{
		std::cout << "Sorry, the Talisman of Truth costs " << price << " gold. You only have " << gold << " gold." << std::endl;
		return false;
	}
	else
	{
		items.push_back("Talisman of Truth");
		gold -= price;
		return true;
	}
}

void Hero::KillHero()
{
	isAlive = false;
}
