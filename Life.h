using std::string;

class Life
{
private:
    string name;
    int attack;
    int defense;
    int stamina;
    int intelligence;

    int stun = 0;
    int weak = 0;   //   attack/2 for number of turns
    int HP;
	int MP;
	int TotalHP;
	int TotalMP; 

    vector<Skill> skills;
  
public:
    void ReportStatus();
    bool checkOwnership()
    /*
	void getName();
  	void getAtt();
  	void getDef();
  	void getStam();
  	void getIntl();
    */

  
};
