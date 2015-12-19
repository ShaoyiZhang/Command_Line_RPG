#include "Dungeon.h"

/*class Dungeon {
private:
	vector<vector<Monster>>stages;
	int size;
	int LevelComplete;
	vector<int>goldByStages;
	vector<int>expByStages;
	//int represent percentage/10
	vector<std::pair<Item, int>> itemsByStage;

public:
	void StartDungeon(Hero & h);
	void LeaveDungeon(Hero* h);
}*/

//increment levelComplete if complete 
void Dungeon::StartDungeon(Hero & h) {

}

void Dungeon::LeaveDungeon(Hero& h) {
	h.GainCoins(goldByStages[LevelComplete - 1]);
	h.GainEXP(expByStages[LevelComplete - 1]);
	srand(time(NULL));
	for (int i = 0; i < LevelComplete; i++) {
		if (rand() % 1000 < itemsByStage[i].second)
			h.GainItem(itemsByStage[i].first);
	}


}
