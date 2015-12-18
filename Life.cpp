#include "Life.h"

Life::Life(string name, int attack, int defense, int stamina, int intelligence,
	       int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills)
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
	this->totalHP = totalHP;
	this->totalMP = totalMP;
	//going to initalize the skills by indexs
	//this->skills = skills;

}