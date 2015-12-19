#include "Life.h"
#include "Hero.h"
#include <iostream>
using namespace std;

int main()
{
	//Life::Life(string name, int attack, int defense, int stamina, int intelligence,
	       //int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<Skill> skills)
	vector<int>temp;
	Life pony = Life("person",1,2,3,4,5,6,7,8,9,10,temp);
	Hero Saber = Hero("Hero", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, temp);


	cout << "pony attack = " << pony.GetAtt();

	cout << "Saber HP = " << Saber.GetHP();
}