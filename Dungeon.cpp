#include "Dungeon.h"


Dungeon::Dungeon(string name, int minimumLevelEnter, const vector<vector<Monster>> &monsters, const vector<vector<vector<char>>> &stages, const vector<int> &goldByStages,
		 const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage) {
  this->name=name;
  this->minimumLevelEnter = minimumLevelEnter;
  this->monsters = monsters;
  this->stages = stages;
  this->itemsByStage = itemsByStage;
  this->goldByStages = goldByStages;
  this->expByStages = expByStages;
  this->itemsByStage = itemsByStage;
  level = stages.size();

  //initalize the Fog_Of_Wall with vetcotr of 10x10 '?'
  vector<char>temp;
  vector<vector<char>> fog;
  for (int i = 0; i < 10; i++)
    temp.push_back('?');
  for (int i = 0; i < 10; i++)
    fog.push_back(temp);

  //0,0 is where hero will be at first
  fog[0][0] = 'H';

  //push for each level
  for (int i = 0; i < level; i++)
    Fog_of_War.push_back(fog);

  for(int i =0; i<level; i++)
    this->levelClear.push_back(false);
}

Dungeon::Dungeon(string name, int minimumLevelEnter, const vector<vector<Monster>> &monsters, string s1, const vector<int> &goldByStages,
		 const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage) {
  this->name=name;
  this->minimumLevelEnter = minimumLevelEnter;
  this->monsters = monsters;
  this->itemsByStage = itemsByStage;
  this->expByStages = expByStages;
  this->goldByStages = goldByStages;
  this->itemsByStage = itemsByStage;
  level = s1.size() / 100;
  int index = 0;
  if (s1.size()%100 != 0) {
    cerr << "size of the string not match" << endl;
  }
  for (int L = 0; L < level; L++) {
    stages.push_back(vector<vector<char>>());
    for (int i = 0; i < 10; i++) {
      stages[L].push_back(vector<char>());
      for (int j = 0; j < 10; j++) {
	stages[L][i].push_back(s1[index]);
	index++;
      }
    }
  }


  //initalize the Fog_Of_Wall with vetcotr of 10x10 '?'
  vector<char>temp;
  vector<vector<char>> fog;
  for (int i = 0; i < 10; i++)
    temp.push_back('?');
  for (int i = 0; i < 10; i++)
    fog.push_back(temp);

  //0,0 is where hero will be at first
  fog[0][0] = 'H';

  //push for each level
  for (int i = 0; i < level; i++)
    Fog_of_War.push_back(fog);

  for(int i =0; i<level; i++)
    this->levelClear.push_back(false);
}

void Dungeon::DisplayFogAtLevel(int n) {
  int size = monsters[n-1].size();
  for (int i = 0; i < 10; i++) {
    for (int k = 0; k < 41; k++){
      cout<<"-";
    }
    cout<<endl;
    cout<<"| ";
    for (int j = 0; j < 10; j++) {
      std::cout << Fog_of_War[n-1][i][j] << " | ";
    }

    if(i/2<size){
      if(i%2==0){
	cout<<"Monster No."<<i/2<<"  "<<monsters[n-1][i/2].To_String_Part_One();
      }
      else
	cout<<"  "<<monsters[n-1][i/2].To_String_Part_Two();
    }
    cout<<endl;
  }
  for (int i = 0; i < 41; i++){
    cout<<"-";
  }
  cout << endl << endl;
}

using namespace std;

int GetDirection()
{
  int ret = 0;

  do
    {
      char c = ' ';
      c = cin.get();
      switch (c)
	{
	case 'w':
	  ret = 2; // top
	  break;
	case 'a':
	  ret = 1; // left 
	  break;
	case 'd':
	  ret = 3; // right
	  break;
	case 's':
	  ret = 4; // down
	  break;
	case 'q':
	  ret = 5;
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
    }
    if (playerY < 9) {
      Fog_of_War[currentLevel][playerX - 1][playerY + 1] = stages[currentLevel][playerX - 1][playerY + 1];
    }
  }
  if(playerY>0)
    Fog_of_War[currentLevel][playerX][playerY - 1] = stages[currentLevel][playerX][playerY - 1];
  if(playerY<9)
    Fog_of_War[currentLevel][playerX][playerY + 1] = stages[currentLevel][playerX][playerY + 1];
  if (playerX < 9) {
    Fog_of_War[currentLevel][playerX + 1][playerY] = stages[currentLevel][playerX + 1][playerY];
    if (playerY > 0) {
      Fog_of_War[currentLevel][playerX + 1][playerY - 1] = stages[currentLevel][playerX + 1][playerY - 1];
    }
    if (playerY < 9) {
      Fog_of_War[currentLevel][playerX + 1][playerY + 1] = stages[currentLevel][playerX + 1][playerY + 1];
    }
  }
}


//increment levelComplete if complete 
void Dungeon::StartDungeon(Hero & h) {
  //space represents nothing, H represents hero, number 0-9 represents monsters, T represents trap, 
  //I represents Item, C reprents Coins, E reprents exit
  int directiopn = 0;
  char command = ' ';
  for (int L = 0; L < level; L++) {
    cout<<"Enter w,a,s,d to move and q to quit\n";
    while (true) {
      //Replace the current Hero location with the origin Item/Monster/Space
      DisplayFogAtLevel(L + 1);
      Fog_of_War[L][playerX][playerY] = stages[L][playerX][playerY];
      directiopn = GetDirection();
      if (directiopn == 1 && playerY > 0)
	playerY -= 1;
      else if (directiopn == 2 && playerX > 0)
	playerX -= 1;
      else if (directiopn == 3 && playerY < 9)
	playerY += 1;
      else if (directiopn == 4 && playerX < 9)
	playerX += 1;
      else{
	LeaveDungeon(h);
	return;
      }
      Fog_of_War[L][playerX][playerY] = 'H';

      //Check if current position is a Entrance to Next Level
      if(stages[L][playerX][playerY]=='E'){
	cout<<"Do you want to Enter Next Level?\nEnter Y to confirm\n";
	cin>>command;
	if(command == 'Y'||command == 'y'){
	  cout<<"You will be tranport to next Level. Goold luck, Hero\n";
	  this->LevelComplete++;
	  break;
	}
      }
      //Display the 8 blocks near the hero
      ClearAllNearBlock();
    }
  }
  cout<<"\nWow, you have complete all level of " <<this->name<<"\n";
  LeaveDungeon(h);
}





void Dungeon::LeaveDungeon(Hero& h) {
  if(LevelComplete==0){
    cout<<"It is too sad that you did not complete even first level\nGo home, kid\n";
    return;
  }

  //check if hero clear all of the monster at certain level
  bool clearThisLevel = true;
  for(int i =0; i<LevelComplete; i++){
    for(int j=0; j<10; j++){
      for(int k=0; k<10; k++){
	if(isdigit(stages[i][j][k])){
	  clearThisLevel = false;
	  break;
	}
      }
      if(!clearThisLevel){
	break;
      }
    }
    if(clearThisLevel){
      levelClear[i]=true;
    }
    clearThisLevel = true;
  }

  
  srand(time(NULL));
  int coinGet = 0;
  int expGet = 0;
  
  for(int i=0; i<LevelComplete; i++){
    if(levelClear[i]){
      coinGet+=goldByStages[i];
      expGet+=expByStages[i];
    }
  }
  h.GainCoins(coinGet);
  h.GainEXP(expGet);

  cout<<"You have complete "<<LevelComplete<<" levels\n";
  cout<<"The level that hero clear is: ";
  for(int i =0; i<LevelComplete; i++)
    if(levelClear[i]==true)
      cout<<"level "<<i+1<<" ";
  cout<<endl;
  cout<<"Bonus Gold: "<<coinGet<<endl;
  cout<<"Bonus EXP: "<<expGet<<endl;

  //bonus Item
  for (int i = 0; i < LevelComplete; i++) {
    if(levelClear[i]){
      if (rand() % 1000 < itemsByStage[i].second){
	cout<<"Bonus Item: "<<itemsByStage[i].first.GetName()<<endl;
	h.GainItem(itemsByStage[i].first);
      }
    }
  }


}
