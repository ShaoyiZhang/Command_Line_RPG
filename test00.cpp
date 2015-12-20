#include "Hero.h"
#include "SaveAndLoad.cpp"

int main() {
	//Hero(string name, int attack, int defense, int stamina, int intelligence,
		//int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills)

	vector<int>temp;
	Life pony = Life("person", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, temp);
	Hero Saber = Hero("Saber", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, temp);


	cout << "pony attack = " << pony.GetAtt()<<endl;

	cout << "Saber HP = " << Saber.GetHP()<<endl;

	Save(Saber);

	string unen = "it is a unencrypt string\n";
	cout << unen;
	Encrypt(unen);
	cout << unen << endl;
	Decrypt(unen);
	cout << unen << endl;

	Load();
}
