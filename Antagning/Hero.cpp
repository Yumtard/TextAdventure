#include "Hero.h"

Hero::Hero(int health_in, int gold_in)
	:
	health(health_in),
	gold(gold_in),
	rng(std::random_device()())
{
}

//Sets Hero health to the Maximum amount
void Hero::Heal()
{
	health = maxHealth;
}

//Adds the passed amount of gold
void Hero::AddGold(int amount)
{
	gold += amount;
}

//Displays hero stats
void Hero::Status() const
{
	std::cout << "Health: " << health << "/" << maxHealth << std::endl;
	std::cout << "Gold: " << gold << std::endl;
	std::cout << "Items: ";

	//If hero has no items
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
	//Produce two random number 0-20 for damage amd 1-10 for reward 
	//subrtacts damage from health and adds reward to gold
	std::uniform_int_distribution<int> randomDmg(0, 20);
	std::uniform_int_distribution<int> randomReward(1, 10);
	damage = randomDmg(rng);
	reward = randomReward(rng) * charmMultiplier;
	health -= damage;
	gold += reward;

	//if health reaches 0 or lower, Hero is no longer alive
	if (health <= 0)
	{
		isAlive = false;
	}

	//Displays this message unless health reached 0 or below
	if (isAlive)
	{
		std::cout << "You kill the monster without mercy. Mercilessly." << std::endl;
		std::cout << "You take " << damage << " damage! You recieve " << reward << " gold." << std::endl;
	}
}

//Buys the charm of Capitalism
//If not enough gold, user gets a message and the function returns false
// if enough gold, the price is subtracted from gold and the item is added to the item vector and the function returns true
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

//Used to kill hero instantly.
//Gets called if Hero enters the Twilight Cave without the Talisman of Truth
void Hero::KillHero()
{
	isAlive = false;
}
