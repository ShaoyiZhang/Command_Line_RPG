#include "Hero.h"
#include <algorithm>

using std::sort;
/*
Hero::Hero(string name, int attack, int defense, int stamina, int intelligence,
           int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills)
{
	Life(name, attack, defense, stamina, intelligence, stun, weak, HP, MP, totalHP, totalMP, skills);
}*/

Hero::Hero(string name):Life()
{
	// randomly create three point in (0,100)
	// use those points to find four interval which sums up to 100
	// use the length of intervals to set four attributes of our hero
	vector<int> arrayOfPoints;

	arrayOfPoints.push_back(int(rand() % 100));
	arrayOfPoints.push_back(int(rand() % 100));
	arrayOfPoints.push_back(int(rand() % 100));

	sort(arrayOfPoints.begin(), arrayOfPoints.end());

	this->attack = arrayOfPoints[0];
	this->defense = arrayOfPoints[1] - arrayOfPoints[0];
	this->stamina = arrayOfPoints[2] - arrayOfPoints[1];
	this->intelligence = 100 - arrayOfPoints[2];

	this->ownership = 0;
	this->coins = 1000;
	this->level = 1;
	this->experience = 0;
	this->bag = Bag();

}

bool Hero::CheckLevelUp()
{
	return false;
}
bool Hero::CheckOwnership(Item& item)
{
	return false;
}
bool Hero::useItem(string itemName)
{
	return false;
}
void Hero::UpdateLevel()   // might call CheckLevelUp()
{
}
bool Hero::PurchaseItem(string itemName)
{
	return false;
}
bool Hero::SellItem(string itemName)
{
	return false;
}
