#include "Monster.h"

/*class Monster : public Life {
private:
	vector<std::pair<Item, int>>dropItems;
	int gold;
	int EXP;
public:
	int GiveGold();
	int GiveEXP();
	vector<Item> DropOff();
};*/

void Monster::ShowInformation(){
  cout<<"\nName: "<<specialType<<GetName()<<endl;
  cout<<"HP: "<<GetHP()<<endl;
  cout<<"ATT: "<<GetAtt()<<endl;
  cout<<"DEF: "<<GetDef()<<endl;
  cout<<"INT: "<<GetIntl()<<endl;
}



int Monster::GiveEXP() {
	return EXP;
}

//return 50%+ rand() amount of gold
int Monster::GiveGold() {
	int temp = gold / 2;
	srand(time(NULL));
	temp = rand() % temp;
	return gold / 2 + temp;
}

vector<Item> Monster::DropOff() {
	vector<Item> drops;
	srand(time(NULL));
	for (std::pair<Item, int> p : dropItems) {
		if (rand() % 1000 < p.second)
			drops.push_back(p.first);
	}
	return drops;
}


void Monster::DefeatedBy(Hero& h){
  int coins = GiveGold();
  h.GainCoins(coins);
  h.GainEXP(GiveEXP());
  cout<<"Gold gained: "<<coins<<endl;
  cout<<"EXP gained: "<<EXP<<endl;
  vector<Item>temp = DropOff();
  if(temp.size()!=0){
    cout<<"Items:\n";
    for(int i=0; i<temp.size();i++){
      h.GainItem(temp[i]);
      cout<<i+1<<". "<<temp[i].GetName()<<endl;
    }
  }
  
  
}

string Monster::To_String_Part_One(){
  string result = "";
  result+=(this->GetName()+"   ");
  result+=("HP: "+to_string(this->GetHP())+"   ");
  result+=("MP: "+to_string(this->GetMP()));
  return result;
}

string Monster::To_String_Part_Two(){
  string result = "";
  result+=("ATT: " + to_string(this->GetAtt())+"   ");
  result+=("DEF: "+to_string(this->GetDef())+"   ");
  result+=("EXP: "+to_string(this->EXP)+"   ");
  result+=("Gold "+to_string(this->gold/2)+"~"+to_string(this->gold));
  return result;
}

void Monster::SetSpecial(){
  int index = 0;
  special = true;
  gold*=2;
  EXP*=2;
  
  index = rand()%4;
  if(index==0){
    specialType = "Rage ";
    attack*=2;
  }
  else if(index==1){
    specialType = "Tenacity ";
    defense*=2;
  }
  else if(index==2){
    specialType = "Strong ";
    stamina*=2;
  } 
  else if(index==3){
    specialType = "Clever ";
    intelligence*=2;
  }
}
