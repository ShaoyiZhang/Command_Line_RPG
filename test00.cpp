#include "Life.h"
#include "Hero.h"
#include <iostream>
using namespace std;

int main()
{
	Life pony = Life(0,1,2,3,4,5,6,7,8,9,10);
	Hero Saber = Hero(0,1,2,3,4,5,6,7,8,9,10);


	cout << "pony attack = " << pony.GetAtt();

	cout << "Saber HP = " << Saber.GetHP(); 
}