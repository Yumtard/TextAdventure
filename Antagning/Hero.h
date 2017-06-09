#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <random>

class Hero
{
public:
	Hero(int health_in, int gold_in);
	Hero() = default;
	void Heal();
	void AddGold(int amount);
	void Status() const;
	bool IsAlive() const;
	int MaxHealth() const;
	void KillMonster(int charmMultiplier);
	bool BuyCharm(int price);
	bool BuyTalisman(int price);
	void KillHero();

private:
	std::mt19937 rng;
	int health;
	static constexpr int maxHealth = 100;
	int gold;
	std::vector<std::string> items;
	bool isAlive = true;
	int damage;
	int reward;
};