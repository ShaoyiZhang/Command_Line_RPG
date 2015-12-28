#include "Dungeon.h"


Dungeon::Dungeon(const vector<vector<Monster>> &monsters, const vector<vector<vector<char>>> &stages, const vector<int> &goldByStages,
	const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage) {
	this->monsters = monsters;
	this->stages = stages;
	this->itemsByStage = itemsByStage;
	this->expByStages = expByStages;
	this->itemsByStage = itemsByStage;
	level = stages.size();

	//initalize the Fog_Of_Wall with vetcotr of 7x7 '?'
	vector<char>temp;
	vector<vector<char>> fog;
	for (int i = 0; i < 7; i++)
		temp.push_back('?');
	for (int i = 0; i < 7; i++)
		fog.push_back(temp);

	//0,0 is where hero will be at first
	fog[0][0] = 'H';

	//push for each level
	for (int i = 0; i < level; i++)
		Fog_of_War.push_back(fog);
}

Dungeon::Dungeon(const vector<vector<Monster>> &monsters, string s1, const vector<int> &goldByStages,
	const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage) {
	this->monsters = monsters;
	this->itemsByStage = itemsByStage;
	this->expByStages = expByStages;
	this->itemsByStage = itemsByStage;
	level = s1.size() / 49;
	int index = 0;
	if (s1.size()%49 != 0) {
		cerr << "size of the string not match" << endl;
	}
	for (int L = 0; L < level; L++) {
		stages.push_back(vector<vector<char>>());
		for (int i = 0; i < 7; i++) {
			stages[L].push_back(vector<char>());
			for (int j = 0; j < 7; j++) {
				stages[L][i].push_back(s1[index]);
				index++;
			}
		}
	}


	//initalize the Fog_Of_Wall with vetcotr of 7x7 '?'
	vector<char>temp;
	vector<vector<char>> fog;
	for (int i = 0; i < 7; i++)
		temp.push_back('?');
	for (int i = 0; i < 7; i++)
		fog.push_back(temp);

	//0,0 is where hero will be at first
	fog[0][0] = 'H';

	//push for each level
	for (int i = 0; i < level; i++)
		Fog_of_War.push_back(fog);
}

void Dungeon::DisplayFogAtLevel(int n) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			std::cout << Fog_of_War[n-1][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

using namespace std;

int GetDirection()
{
	int ret = 0;

	do
	{
		int ch = _getch();
		if (isascii(ch))
			continue;

		ch = _getch();
		switch (ch)
		{
		case 72:
			ret = 2; // top
			break;
		case 75:
			ret = 1; // left 
			break;
		case 77:
			ret = 3; // right
			break;
		case 80:
			ret = 4; // down
			break;
		default:
			break;
		}
	} while (ret == 0);

	return ret;
}

void Dungeon::ClearAllNearBlock() {
	int currentLevel = LevelComplete;
	if (playerX > 0) {
		Fog_of_War[currentLevel][playerX - 1][playerY] = stages[currentLevel][playerX - 1][playerY];
		if (playerY > 0) {
			Fog_of_War[currentLevel][playerX - 1][playerY - 1] = stages[currentLevel][playerX - 1][playerY - 1];
			Fog_of_War[currentLevel][playerX][playerY - 1] = stages[currentLevel][playerX][playerY - 1];
		}
		if (playerY < 6) {
			Fog_of_War[currentLevel][playerX - 1][playerY + 1] = stages[currentLevel][playerX - 1][playerY + 1];
			Fog_of_War[currentLevel][playerX][playerY + 1] = stages[currentLevel][playerX][playerY + 1];
		}
	}
	if (playerX < 6) {
		Fog_of_War[currentLevel][playerX + 1][playerY] = stages[currentLevel][playerX + 1][playerY];
		if (playerY > 0) {
			Fog_of_War[currentLevel][playerX + 1][playerY - 1] = stages[currentLevel][playerX + 1][playerY - 1];
		}
		if (playerY < 6) {
			Fog_of_War[currentLevel][playerX + 1][playerY + 1] = stages[currentLevel][playerX + 1][playerY + 1];
		}
	}
}


//increment levelComplete if complete 
void Dungeon::StartDungeon(Hero & h) {
	//space represents nothing, H represents hero, number 0-9 represents monsters, T represents trap, 
	//I represents Item, C reprents Coins, E reprents exit
	int directiopn = 0;
	for (int L = 0; L < level; L++) {
		while (true) {
			//Replace the current Hero location with the origin Item/Monster/Space
			DisplayFogAtLevel(L + 1);
			Fog_of_War[L][playerX][playerY] = stages[L][playerX][playerY];
			directiopn = GetDirection();
			if (directiopn == 1 && playerY > 0)
				playerY -= 1;
			else if (directiopn == 2 && playerX > 0)
				playerX -= 1;
			else if (directiopn == 3 && playerY < 6)
				playerY += 1;
			else if (directiopn == 4 && playerX < 6)
				playerX += 1;
			Fog_of_War[L][playerX][playerY] = 'H';
			//Display the 8 blocks near the hero
			ClearAllNearBlock();
		}
	}
}

void Dungeon::LeaveDungeon(Hero& h) {
	h.GainCoins(goldByStages[LevelComplete]);
	h.GainEXP(expByStages[LevelComplete]);
	srand(time(NULL));
	for (int i = 0; i < LevelComplete; i++) {
		if (rand() % 1000 < itemsByStage[i].second)
			h.GainItem(itemsByStage[i].first);
	}


}
