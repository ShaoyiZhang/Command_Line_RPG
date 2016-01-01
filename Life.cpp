#include "Life.h"
#include <stdlib.h>



Life::Life(string name, int attack, int defense, int stamina, int intelligence,
	   int stun, int weak,int HP, int MP ,vector<int> skills)
{
	this->name = name;
	this->attack = attack;
	this->defense = defense;
	this->stamina = stamina;
	this->intelligence = intelligence;
	this->stun = stun;
	this->weak = weak;
	this->HP = HP;
	this->MP = MP;
	this->totalHP = stamina*4;
	this->totalMP = intelligence*4;
	//going to initalize the skills by indexs
	//this->skills = skills;
}

Life::Life(string name, int attack, int defense, int stamina, int intelligence, vector<int> skills)
{
  	this->name = name;
  	this->attack = attack;
  	this->defense = defense;
  	this->stamina = stamina;
  	this->intelligence = intelligence;
  	this->totalHP = stamina*4;
	this->totalMP = intelligence*4;
	this->HP = totalHP;
	this->MP = totalMP;
  	// initialize skills

}


