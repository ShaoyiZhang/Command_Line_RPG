#include "Hero.h"
#include <algorithm>
#include <time.h>
#include <iostream>
#include <cstdlib>
using std::endl;
using std::cout;
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

	srand(time(NULL));
	arrayOfPoints.push_back(int(rand() % 100));
	srand(time(NULL));
	arrayOfPoints.push_back(int(rand() % 100));
	srand(time(NULL));
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

void Hero::PrintLevel()
{
	cout<<"Master, your level is " << this->level << "." << endl;
}

void Hero::PrintCoins()
{
	cout<<"Master, you have " << this->coins << "Hero coins." << endl;
}
void Hero::PrintEXP()
{
	cout<<"Master, you have " << this->experience << "EXP. To level up, you still need "<< (this->maxEXP - this->experience) << "EXP. Keep it up!" << endl;
}
bool Hero::CheckLevelUp()
{
	if (this->maxEXP <= this->experience)
		return false;
  	else
	{
		this->experience = this->experience - maxEXP;
		this->level++;
		return true;
    }
}
bool Hero::CheckOwnership(Item& item)
{
	return false;
}
// ########################### TO DO ##############################
void Hero::UseItem(int itemNum)
{
}


bool Hero::UseItem(int itemNum, Hero &h, Monster &m)
{
  	if (this->bag.UseItem(itemNum))
  	{
  		cout << "Sussesfully used.";
  		return true;
  	}
  	else
  	{
  		cout << "Fail to use item!";
  		return false;
  	}
}
/*
void Hero::useItem(Item item)
{
	this->bag.UseItem(item);
}*/
void Hero::UpdateLevel()   // might call CheckLevelUp()
{
}
bool Hero::PurchaseItem(string itemName)
{
	return false;
}

bool Hero::PurchaseItem(Item item)
{
	return false;
}
void Hero::PurchaseItem(Item item, int howMany)
{
	if ((item.GetBuyPrice() * howMany) < this->coins)
	{
		cout << "Insufficient gold! Earn more money!";
	}
	else
	{
		cout << "Bought " << howMany << " " << item.GetName() << "s sussesfully!\n";
		cout << "Continue purchasing? Enter Y for yes, N for no \n";
		//bool continue = false;
		//cin >> continue;
		//if (continue)

	}
}
bool Hero::SellItem(string itemName)
{
	return false;
}
bool Hero::SellItem(Item item)
{
	return false;
}
bool Hero::SellItem(string itemName, int howMany)
{
	return false;
}

