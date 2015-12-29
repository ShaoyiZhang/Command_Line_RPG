#include "World.h"

World::World(Hero hero, Dungeon dungeons, vector<NPC>npcs) {
	this->hero = hero;
	this->dungeons = dungeons;
	this->npcs = npcs;
}


void World::FightInstruction()
{
    cout << "It's your turn. You can chose from: "
    << "1. Attack\n"
    << "2. Defense\n"		// For now, it means do nothing
    << "3. Use Skill\n"
    << "4. Use Item\n"
    << "Pleas enter a number and press enter";
    //<< "If you're Pro, try action number+P to "
}

void World::Help()
{
    
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

void World::Attack(Hero &h, Monster &m, int attacker)  // 0 for monster, 1 for hero
{
    
}

void World::MonsterTurn(Hero &h, Monster &m)
{
    
}

void World::Fight(Hero &h, Monster &m)
{
	Fight(h,m,0);
}

void World::Fight(Hero &h, Monster &m, int pro)
{
	if (h.GetHP() <= 0)
	{
		cout << "You are defeated, Master. I will wait for your respawn in GG valley ...";
		this->dungeons.LeaveDungeon(h);
	}
	else
	{
		if (pro == 0)
			FightInstruction();
		cout << "Pro Mode, Your Turn:";
        int instruction;
		cin >> instruction;
		
		switch (instruction)
		{
			case 1:		// Attack
            {
				m.UpdateHP(h.GetAtt()-m.GetDef()>m.GetHP()?0:h.GetAtt()-m.GetDef());
				break;
            }
			case 2:		// Defense
            {
                break;
            }
			case 3:		// Use Skill
            {
                cout << "Which skill do you want to use?";
				if (pro == 0)
					h.SkillsToString();
				int skillNum = -1;
				cin >> skillNum;
				h.UseSkill(skillNum);
				break;
            }
			case 4:		// Use Item
            {
                cout << "Which item do you want to use?";
				if (pro == 0)
					h.GetBag().ToString();
				int itemNum = -1;
				cin >> itemNum;
				h.UseItem(itemNum);
				break;
            }
			case 0:		// Pro mode
            {
                Fight(h,m,1);
				return;
				break;
            }
			case 9:		// Call for Help
            {
                this->Help();
				break;
            }
			defalt:
            {
				cerr << "wrong button pressed!";
				Fight(h,m,pro);
				return;
            }
		}
		MonsterTurn(h,m);
		Fight(h,m,pro);
	}
}










