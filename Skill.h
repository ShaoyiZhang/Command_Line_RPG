#ifndef SKILL_H_
#define SKILL_H_
#include <string>
#include <utility>
#include <map>
#include <vector>
using std::string;
using std::map;
using std::pair;
using std::vector;

// Skill class is a libray that contains multiple Single Skills
// To use a skill, try UseSkill("Ex-Calibur") or UseSkill(1)

class Skill
{
private:
	class SingleSkill
	{
	private:
		// first choose wchih attributes(index 0 ~ 3) to modify (use the key value of type int)
		// then choose which operator(+,*) and the amount of modification
		// pair(operator, amount)
		// by using an operator, we can not only change attributes by plus and minus
		// but can change them by percentage

		// TO DO ...................
		// index: 0 attack, 1 defense, 2 stamina, 3 intelligence, 4 stun, 
		// operator: 0 for +, 1 for *, -1 for stay the same


		vector<pair<int,int>> modifySelfAttributes;
		vector<pair<int,int>> modifyMonsterAttributes;
		//vector<int> actions
	public:
		SingleSkill(vector<pair<int,int>> modifySelfAttributes, vector<pair<int,int>> modifyMonsterAttributes);
		
		// target: 0 for self, 1 for monster
		void AddAbility(int target, int attribute, int symbol, int amount);
	};
	// give skill number(array index) to specific skill -- a pair of skill name and skill property
	vector<pair<string,SingleSkill>> skillLibrary;

public:
    Skill(){}
    Skill(vector<pair<string,SingleSkill>> setOfSkills);

    // returns skill number(mapped value) for the new skill
    int AddSkill(pair<string,SingleSkill> oneSkill);

    bool UseSkill(string skillName);
    bool UseSkill(int skillNumber);
    
    // print out: 1. skill number
   	// 			  2. skill name
   	// 			  3. skill property
    string toString() const;
};
#endif