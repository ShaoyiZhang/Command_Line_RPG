#include "World.h"
/*
class World {
private:
	Hero hero;
	vector<Dungeon> dungeons;
	int villageX = 0;
	int villageY=0;
	vector<vector<char>village;
	//vector<NPC> npcs;
public:
	World(Hero hero, Dungeon dungeons);
	void StartGame();
	void DisplayVillage();
	void Save(Hero& h);
	void Load();
    

	
	};*/

World::World(){
  
}

World::World(const Hero& hero, const vector<Dungeon>& dungeons,  vector<NPC>npcs) {
    this->hero = hero;
    this->dungeons = dungeons;
    this->npcs = npcs;
    string s(100,' ');
    s[0]  = 'S';//starting point
    s[5]  = 'R';//where hero would be when it is back from Dungeon
    s[49] = 'A';//Save and Exit
    s[43] = 'M';//A Merchant that can sell and buy Item
    s[56] = 'W';//A black smith that can upgrade your weapon and equiments
    s[95] = 'E'; //Entrance to the Dungeon
    int index =0;
    vector<char>c;
    for(int i =0; i<10; i++)
      this->village.push_back(c);
    for(int i =0; i<10; i++){
      for(int j=0; j<10; j++){
	village[i].push_back(s[index]);
	index++;
      }
    }
    current = village;
}


void World::DisplayVillage(){
  cout<<endl;
  for(int i =0; i<43; i++)
    cout<<"-";
  cout<<endl;


  for(int i =0; i<10; i++){
    cout<<"| ";
    for(int j=0; j<10; j++){
      cout<<current[i][j]<<" | ";
    }
    cout<<endl;
    for(int k=0; k<43; k++)
      cout<<"-";
    cout<<endl;
  }
}


int GetVillageDire()
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
	default:
	  break;
	}
    } while (ret == 0);

  return ret;
}


void World::DisplayDungeons(){
  int size = this->dungeons.size();
  for(int i =0; i<size; i++){
    cout<<i<<". "<<dungeons[i].GetName()<<"      Minimum Level Enter: "<<dungeons[i].GetMinLevel() <<endl;
  }
}
void World::EnterDungeon(){
  int size = this->dungeons.size();
  DisplayDungeons();
  cout<<"Enter the index of the Dungeon you want to enter\n";
  char index = ' ';
 again:
  cin>>index;
  while((int)(index-'0')<0||(int)(index-'0')>=size){
    if(index == 'q'||index == 'Q')
      return;
    cout<<"Index is invalid, please enter again:\nEnter Q to exit\n";
    cin>>index;
  }
  if(dungeons[(int)(index-'0')].GetMinLevel()>hero.GetLevel()){
    cout<<"You did not meet the minimum level. Try another Dungeon please\n";
    goto again;
  }
  Dungeon copy = dungeons[(int)(index-'0')];
  copy.Reset();
  copy.StartDungeon(hero);
}



void World::StartGame(){
  char command = ' ';
  int direction =0;
  while(true){
    current[villageX][villageY] = 'H';
    DisplayVillage();
    direction = GetVillageDire();
    current[villageX][villageY] = village[villageX][villageY];
    if (direction == 1 && villageY > 0)
      villageY-= 1;
    else if (direction == 2 && villageX > 0)
      villageX -= 1;
    else if (direction == 3 && villageY < 9)
      villageY += 1;
    else if (direction == 4 && villageX < 9)
      villageX += 1;
    //check if current position is a Entrance
    if(village[villageX][villageY]=='E'){
      EnterDungeon();
      villageX =0;
      villageY = 5;
      cout<<"Welcome home, hero!\n";
    }
    else if(village[villageX][villageY]=='A'){
      cout<<"Do you want to save the data? Enter Y to confirm\n";
      cin>>command;
      if(command=='y'||command == 'Y'){
	//To Do:
	//Ask which data player want to save 
	cout<<"Do you want to exit the game? Enter Y to confirm\n";
	cin>>command;
	if(command=='y'||command == 'Y'){
	  cout<<"GoodBye\n";
	  break;
	}
      }
    }

    //check if current position is a Merchant
    else if(village[villageX][villageY]=='M'){
      cout<<"What's my name? I am not going to tell you that. Do you want to do the business or not?\n\n";
    again:
      cout<<"\nYou have following options\n";
      cout<<"1. Talk with this mercahnt\n";
      cout<<"2. Buy Items from him\n";
      cout<<"3. Sell Items to him\n";
      cout<<"q. Exit\n";
      cout<<"What are you going to do? Enter the Index: \n";
      cin>>command;
      while(command!='1'&&command!='2'&&command!='3'){
	if(command=='q'||command=='Q')
	  break;
	cout<<"Invalid command. Please enter the index again\n";
	cout<<"Enter Q to quit conversion\n";
      }
      cout<<endl;
      if(command=='1')
	npcs[0].Talking(hero);
      else if(command=='2')
	npcs[0].Buy(hero);
      else if(command == '3')
	npcs[0].Sell(hero);
      if(command!='q'&&command!='Q')
	goto again;
      
    }

    
  }
}




























string GetNextWord(string &contents, int &index) {
    int size = contents.size();
    if (index >= size) return "";
    string temp = "";
    while ((contents[index] == ' ' || contents[index] == '\n') && index < (size - 1))
        index++;
    for (; index < size; index++) {
        if (contents[index] != ' '&& contents[index] != '\n')
            temp += contents[index];
        else break;
    }
    return temp;
}

void Encrypt(string & string) {
    for (char& c : string) {
        c = (c + 10);
    }
}

void Decrypt(string & string) {
    for (char& c : string) {
        c = (c - 10);
    }
}


void World::Load() {
    std::ifstream myfile("SAVE_DATA.txt");
    string input = "";
    string temp = "";
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, temp);
            input += temp;
            input += "\n";
        }
    }

    if (input == "")
        return;

    int size = input.size(), i = 0;

    Decrypt(input);

    string name = "", tp = "";
    int Level = 0, EXP = 0, Attack = 0, Defense = 0, Stamina = 0, Intelligence = 0, HP = 0;
    int TotalHP = 0, TotalMP = 0, MP = 0, coins = 0, holder1 = 0, holder2 = 0;
    vector<int>skills;
    vector<pair<int, int>>Bag;

    GetNextWord(input, i);
    name = GetNextWord(input, i);
    GetNextWord(input, i);
    Level = stoi(GetNextWord(input, i).c_str());
    GetNextWord(input, i);
    EXP = stoi(GetNextWord(input, i).c_str());
    GetNextWord(input, i);
    Attack = stoi(GetNextWord(input, i).c_str());;
    GetNextWord(input, i);
    Defense = stoi(GetNextWord(input, i).c_str());;
    GetNextWord(input, i);
    Stamina = stoi(GetNextWord(input, i).c_str());;
    GetNextWord(input, i);
    Intelligence = stoi(GetNextWord(input, i).c_str());;
    GetNextWord(input, i);
    HP = stoi(GetNextWord(input, i).c_str());
    GetNextWord(input, i);
    TotalHP = stoi(GetNextWord(input, i).c_str());;
    GetNextWord(input, i);
    MP = stoi(GetNextWord(input, i).c_str());;
    GetNextWord(input, i);
    TotalMP = stoi(GetNextWord(input, i).c_str());;
    GetNextWord(input, i);
    coins = stoi(GetNextWord(input, i).c_str());
    GetNextWord(input, i);

    while (i<size) {
        tp = GetNextWord(input, i);
        if (tp == "Bag:")
            break;
        skills.push_back(stoi(tp.c_str()));
    }

    while (i<(size - 1)) {
        tp = GetNextWord(input, i);
        int j = 1;
        holder1 = 0;
        holder2 = 0;
        while (j < tp.size()) {
            if (tp[j] == ',')
                break;
            holder1 = holder1 * 10 + (tp[j] - '0');
            j++;
        }
        j++;
        while (j < tp.size()) {
            if (tp[j] == '>')
                break;
            holder2 = holder2 * 10 + (tp[j] - '0');
            j++;
        }
        Bag.push_back(pair<int, int>(holder1, holder2));

    }
    Bag.pop_back();

    cout << "name = " << name << endl;
    cout << "level = " << Level << endl;
    cout << "EXP = " << EXP << endl;
    cout << "ATTACK = " << Attack << endl;
    cout << "coins = " << coins << endl;
    for (int i : skills)
        cout << i;
    cout << endl;
    for (pair<int, int> p : Bag)
        cout << p.first << " " << p.second << endl;
    cout << endl;




}

void World::Save(Hero& h) {
    std::ofstream myfile("SAVE_DATA.txt");
    string temp = "";
    temp += ("Hero: " + h.GetName() + "\n");
    temp += ("Level: " + to_string(h.GetLevel()) + "\n");
    temp += ("EXP: " + to_string(h.GetEXP()) + "\n");
    temp += ("Attack: " + to_string(h.GetAtt()) + "\n");
    temp += ("Defense: " + to_string(h.GetDef()) + "\n");
    temp += ("Stamina: " + to_string(h.GetStam()) + "\n");
    temp += ("Intelligence: " + to_string(h.GetIntl()) + "\n");
    temp += ("HP: " + to_string(h.GetHP()) + "\n");
    temp += ("TotalHP: " + to_string(h.GetTotalHP()) + "\n");
    temp += ("MP: " + to_string(h.GetMP()) + "\n");
    temp += ("TotalMP: " + to_string(h.GetTotalMP()) + "\n");
    temp += ("Coins: " + to_string(h.GetCoins()) + "\n");

    //should use to_string method here
    temp += "Skills: \n";
    temp += "Bag: \n";
    Encrypt(temp);
    myfile << temp;
    myfile.close();

}

