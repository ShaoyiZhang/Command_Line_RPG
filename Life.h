#ifndef LIFE_H_
#define LIFE_H_

#include <string>
#include <vector>
#include "Skill.h"

using std::string;
using std::vector;

class Life
{
protected:
    string name;
    int attack;
    int defense;
    int stamina;
    int intelligence;

    int stun = 0;
    int weak = 0;   //   attack/2 for number of turns
    int HP;
    int MP;
    int totalHP;
    int totalMP; 

    vector<Skill> skills;
  
public:
    void ReportStatus();
    Life(){};
    // 11 attirbutes in total
    Life(string name, int attack, int defense, int stamina, int intelligence,
         int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<int> skills);
    Life(string name, int attack, int defense, int stamina, int intelligence, int totalHP, int totalMP, vector<int> skills);
    string GetName(){ return this->name; };
    int GetAtt(){ return this->attack; };
    int GetDef(){ return this->defense; };
    int GetStam(){ return this->stamina; };
    int GetIntl(){ return this->intelligence; };
    int GetStun(){ return this->stun; };
    int GetWeak(){ return this->weak; };
    int GetHP(){ return this->HP; };
    int GetMP(){ return this->MP; };
    int GetTotalHP(){ return this->totalHP; };
    int GetTotalMP(){ return this->totalMP; };
    void UpdateAtt(int amount){ this->attack+=amount; };
    void UpdateDef(int amount){ this->defense+=amount; };
    void UpdateStam(int amount){ this->stamina+=amount; };
    void UpdateIntl(int amount){ this->intelligence+=amount; };
    void UpdateStun(int amount){ this->stun+=amount; };
    void UpdateWeak(int amount){ this->weak+=amount; };
    void UpdateHP(int amount){ this->HP+=amount; };
    void UpdateMP(int amount){ this->MP+=amount; };
    void UpdateTotalHP(int amount){ this->totalHP+=amount; };
    void UpdateTotalMP(int amount){ this->totalMP+=amount; };

};

#endif