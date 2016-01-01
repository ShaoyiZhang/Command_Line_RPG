#include "Hero.h"



Hero::Hero(string name):Life()
{
	// randomly create three point in (0,100)
	// use those points to find four interval which sums up to 100
	// use the length of intervals to set four attributes of our hero
	vector<int> arrayOfPoints;

	srand(time(NULL));
	arrayOfPoints.push_back(int(rand() % 100));
	srand(time(NULL));
	arrayOfPoints.push_back(int(rand() % 100));
	srand(time(NULL));
	arrayOfPoints.push_back(int(rand() % 100));

	sort(arrayOfPoints.begin(), arrayOfPoints.end());

	this->attack = arrayOfPoints[0];
	this->defense = arrayOfPoints[1] - arrayOfPoints[0];
	this->stamina = arrayOfPoints[2] - arrayOfPoints[1];
	this->intelligence = 100 - arrayOfPoints[2];

	this->ownership = 0;
	this->coins = 1000;
	this->level = 1;
	this->experience = 0;
	this->bag = Bag();

}

void Hero::PrintLevel()
{
	cout<<"Master, your level is " << this->level << "." << endl;
}

void Hero::PrintCoins()
{
	cout<<"Master, you have " << this->coins << " Hero coins." << endl;
}
void Hero::PrintEXP()
{
	cout<<"Master, you have " << this->experience << "EXP. To level up, you still need "<< (this->maxEXP - this->experience) << " EXP. Keep it up!" << endl;
}

void Hero::ReportStatus(){
  cout<<endl;
  PrintLevel();
  PrintCoins();
  PrintEXP();
  cout<<endl;
}

bool Hero::CheckLevelUp()
{
	if (this->maxEXP > this->experience)
		return false;
  	else
	{
		this->experience = this->experience - maxEXP;
		//upgrade the level and set the maxEXP to new value
		this->maxEXP = LevelToUpgrade[++level];
		return true;
    }
}
bool Hero::CheckOwnership(Item& item)
{
	return false;
}

void Hero::UseSkill(int skillNum)
{

}
// ########################### TO DO ##############################
void Hero::UseItem(int itemNum)
{
}


bool Hero::UseItem(int itemNum, Hero &h, Monster &m)
{
  	if (this->bag.UseItem(itemNum))
  	{
  		cout << "Sussesfully used.";
  		return true;
  	}
  	else
  	{
  		cout << "Fail to use item!";
  		return false;
  	}
}

void Hero::GainItem(Item item)
{
	int index = this->bag.FindIndex(item);
	if (index != -1)
	{
		this->bag.UpdateCount(index, 1);
	}
	else
		this->bag.PutInBag(item);
}

void Hero::UpdateLevel()   // might call CheckLevelUp()
{
  if(CheckLevelUp()){
    cout<<"\n\n\n\n\nLevel UP! You are LV."<<level<<" now\n";
    cout<<"You have 4 free attribute points. Choose wisely";
    int points = 4;
    char toAdd = ' ';
    char command = ' ';
    while(points){
      cout<<"Which attribute you want to enhance?\n";
      cout<<"1. Attack\n2. Defense \n3. Stamina \n4.Intelligence\n";
      cout<<"Enter the index";
      cin>>command;
      while(command!='1'&&command!='2'&&command!='3'&&command!='4'){
	cout<<"Only index 1,2,3,4 is valid. Please enter the index again\n";
	cin>>command;
      }
      cout<<"How many points you want to put in this attribute?\n";
      cin>>toAdd;
      while((int)(toAdd-'0')<0||(int)(toAdd-'0')>points){
	cout<<"Invalid number, you have "<<points<<" points now. Enter the number again\n";
	cin>>toAdd;
      }
      if(command=='1')
	this->attack+=(toAdd-'0');
      if(command=='2')
	this->defense+=(toAdd-'0');
      if(command=='3')
	this->stamina+=(toAdd-'0');
      if(command=='4')
	this->intelligence+=(toAdd-'0');
      points-=(int)(toAdd-'0');
      cout<<"You have "<<points<<" points left\n";
    }
    ReportStatus();
    this->totalHP = stamina*4;
    this->totalMP = intelligence*4;
    this->HP = this->totalHP;
    this->MP = this->totalMP;
  }
}

bool Hero::PurchaseItem(string itemName)
{
	return false;
}

bool Hero::PurchaseItem(Item item)
{
	return false;
}
void Hero::PurchaseItem(Item item, int howMany)   // ############### TO DO #####################
{
	if ((item.GetBuyPrice() * howMany) < this->coins)
	{
		cout << "Insufficient gold! Earn more money!";
	}
	else
	{
		cout << "Bought " << howMany << " " << item.GetName() << "s sussesfully!\n";
		cout << "Continue purchasing? Enter Y for yes, N for no \n";
		//bool continue = false;
		//cin >> continue;
		//if (continue)
	}
}
bool Hero::SellItem(string itemName)
{
	return false;
}
bool Hero::SellItem(Item item)
{
	return false;
}
bool Hero::SellItem(string itemName, int howMany)
{
	return false;
}

