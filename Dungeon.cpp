#include "Dungeon.h"


Dungeon::Dungeon(string name, int minimumLevelEnter, const vector<int> &minGold, const vector<int> &maxGold,const vector<vector<Monster>> &monsters, const vector<vector<vector<char>>> &stages, const vector<int> &goldByStages,
		 const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage) {
  this->name=name;
  this->minimumLevelEnter = minimumLevelEnter;
  this->monsters = monsters;
  this->stages = stages;
  this->itemsByStage = itemsByStage;
  this->goldByStages = goldByStages;
  this->expByStages = expByStages;
  this->itemsByStage = itemsByStage;
  this->minGold = minGold;
  this->maxGold = maxGold;
  this->level = stages.size();

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
  
  char tmp = ' ';
  int mIndex = 0;
  //initalize monstersByPosition
  for(int l=0; l<level; l++){
    monstersByPosition.push_back(vector<pair<int,Monster>>());
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
	tmp = stages[l][i][j];
	if(isdigit(tmp)){
	  mIndex = 10*i+j;
	  monstersByPosition[l].push_back(pair<int,Monster>(mIndex,monsters[l][(int)tmp-'0']));
	}
      }
    }
  }
}

Dungeon::Dungeon(string name, int minimumLevelEnter, const vector<int> &minGold, const vector<int> &maxGold, const vector<vector<Monster>> &monsters, string s1, const vector<int> &goldByStages,
		 const vector<int> &expByStages, const vector<std::pair<Item, int>> &itemsByStage) {
  this->name=name;
  this->minimumLevelEnter = minimumLevelEnter;
  this->monsters = monsters;
  this->itemsByStage = itemsByStage;
  this->expByStages = expByStages;
  this->goldByStages = goldByStages;
  this->itemsByStage = itemsByStage;
  this->minGold = minGold;
  this->maxGold = maxGold;
  this->level = s1.size() / 100;
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

  //initalize monstersByPosition
  char tmp = ' ';
  int mIndex = 0;
  for(int l=0; l<level; l++){
    monstersByPosition.push_back(vector<pair<int,Monster>>());
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
	tmp = stages[l][i][j];
	if(isdigit(tmp)){
	  mIndex = 10*i+j;
	  monstersByPosition[l].push_back(pair<int,Monster>(mIndex,monsters[l][(int)tmp-'0']));
	}
      }
    }
  }
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


Monster& Dungeon::GetMonster(int l, int x, int y){
  int index = 10*x+y;
  int size = monstersByPosition[l].size();
  for(int i =0; i<size; i++){
   
    if(monstersByPosition[l][i].first == index){
      return monstersByPosition[l][i].second;
    }
  }
  Monster defaultM;
  return defaultM;;
}





int Dungeon::GetDirection()
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
	  ret = 5;//return
	  break;
	case 'e':
	  autoFight = false;
	  cout<<"Auto fight has been turnned off\n";
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














void Dungeon::Help()
{
    cout << "How can I help you, Master";
}






void Dungeon::FightInstruction()
{
    cout << "It's your turn. You can chose from: \n"
    << "1. Attack\n"
    << "2. Defense\n"       // For now, it means do nothing
    << "3. Use Skill\n"
    << "4. Use Item\n"
    << "5. Turn on Auto fight mode (Enter e to turn off)\n"
    << "7. Enter Pro Mode\n"
    << "8. To Do, Call For Help\n"
    << "9. End Fight(Escape)\n"
    << "Pleas type a number and press Enter\n";
    //<< "If you're Pro, try action number+P to "
}







void Dungeon::Attack(Hero &h, Monster &m, int attacker)  // 0 for monster, 1 for hero
{
    if (attacker == 1) // Hero attacking
    {   
        int damage = h.GetAtt()-m.GetDef()/2<0?0:(h.GetAtt()-m.GetDef());
	cout<<"Monster's defense is "<<m.GetDef()<<endl;
	cout<<"Hero's attack is "<<h.GetAtt()<<endl;
        m.UpdateHP(-damage);
        cout << "\nMonster received " << damage << " damage.\n";
        cout << "Monster HP: " << m.GetHP() << std::endl<<endl;
    }
    else if(attacker == 0)
     {
        int damage = m.GetAtt()-h.GetDef()<0?0:(m.GetAtt()-h.GetDef());
        h.UpdateHP(-damage);
        cout << "You received " << damage << " damage.\n";
        cout << "Hero HP: " << h.GetHP() << std::endl<<endl;;
    }
    else
    {    
        cout << "Error: Invalid Attacker!\n";
    }
}

void Dungeon::MonsterTurn(Hero &h, Monster &m)
{
    //srand(time(NULL));

    // Temperory solution for testing, monster only attack
    this->Attack(h,m,0);
    //cout << m.GetName() << "has gave you " << da;
}

void Dungeon::Fight(Hero &h, Monster &m)
{
    Fight(h,m,0);
}

void Dungeon::Fight(Hero &h, Monster &m, int pro)
{
    if (h.GetHP() <= 0)
    {
        cout << "You have been defeated by " << m.GetName() << " , Master. I will wait for your respawn in GG valley ...\n\n";
    }
    else if (m.GetHP() <= 0)
    {
        cout << "You have defeated " << m.GetName() << " .\n";
	m.DefeatedBy(h);
        return;
    }
    else
    {
        if (pro == 7)
            cout << "Pro Mode, Your Turn:  ";
        else
            FightInstruction();
        char instruction=0;
	
	if(autoFight)
	  instruction = '1';
	else
	cin>>instruction;
	
	if(instruction == '5'){
	  autoFight = true;
	  instruction = '1';
	}
        
	while((instruction-'0')<1||(instruction-'0')>9){
	  cout<<"Wrong button pressed, only 0~9 is meaningful, try again\n";
	  cin >> instruction;
	  cout<<"Instrcution I get this time is "<<instruction<<endl;
	}
        switch (instruction)
        {
            case '1':     // Attack
            {
                Attack(h,m,1);
                break;
            }
            case '2':     // Defense
            {
                break;
            }
            case '3':     // Use Skill
            {
                cout << "Which skill do you want to use?";
                if (pro != 7)
                    h.SkillsToString();
                int skillNum = -1;
                cin >> skillNum;
                h.UseSkill(skillNum);
                break;
            }
            case '4':     // Use Item
            {
                cout << "Which item do you want to use?";
                if (pro != 7)
                    h.GetBag().ToString();
                int itemNum = -1;
                cin >> itemNum;
                h.UseItem(itemNum);
                break;
            }
            case '7':     // Pro mode
            {
                Fight(h,m,7);
                return;
                break;
            }
            case '8':     // Call for Help
            {
                this->Help();
                break;
            }
            case '9':
            {
              return;
            }
            default:
            {
                return;
            }
        }
        MonsterTurn(h,m);
        Fight(h,m,pro);
    }
}

void Dungeon::PickUpGoldAtLevel(Hero& h, int l){
  srand(time(NULL));
  int temp = rand()%(maxGold[l-1]-minGold[l-1]);
  temp = temp+minGold[l-1];
  cout<<"You just pick up "<<temp<<" coins!\n";
  h.GainCoins(temp);
  return;
}


//increment levelComplete if complete 
void Dungeon::StartDungeon(Hero & h) {
  //space represents nothing, H represents hero, number 0-9 represents monsters, T represents trap, 
  //I represents Item, C reprents Coins, E reprents exit
  int directiopn = 0;
  char command = ' ';
  //L is one less than the current level
  for (int L = 0; L < level; L++) {
    //Reset hero position at start of each level
    playerX = playerY =0;
    cout<<"Enter w,a,s,d to move and q to quit\n";
    while (true) {
      //Display the 8 blocks near the hero
      ClearAllNearBlock();
      //Replace the current Hero location with the origin Item/Monster/Space
      cout<<"HP: "<<h.GetHP()<<"/"<<h.GetTotalHP();
      cout<<"     EXP: "<<h.GetEXP()<<"/"<<h.GetMaxEXP();
      cout<<"                   ATT: "<<h.GetAtt()<<"  Def: "<<h.GetDef();
      cout<<"  STAM: "<<h.GetStam()<<"  INTL: "<<h.GetIntl()<<endl;
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
      else if (directiopn == 5){
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



      //Check if current position is a Monster
      else if(isdigit(stages[L][playerX][playerY])){
	Monster& currentMonster = GetMonster(L,playerX,playerY);
	Fight(h,currentMonster);
	if(h.GetHP()==0){
	  LeaveDungeon(h);
	  return;
	}
	if (currentMonster.GetHP()<=0){
	  stages[L][playerX][playerY] = ' ';
	}
      }


      //check if current position is coins that can be pick Up
      else if(stages[L][playerX][playerY]=='C'){
	PickUpGoldAtLevel(h,L+1);
	stages[L][playerX][playerY] = ' ';
      }



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
