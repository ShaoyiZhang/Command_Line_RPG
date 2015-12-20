#include "Skill.h"

Skill::SingleSkill::SingleSkill(vector<pair<int,int>> modifySelfAttributes, vector<pair<int,int>> modifyMonsterAttributes)
{ 
	this->modifySelfAttributes = modifySelfAttributes;
	this->modifyMonsterAttributes = modifyMonsterAttributes;

}

void Skill::SingleSkill::AddAbility(int target, int attribute, int symbol, int amount)
{
    pair<int,int> skillProperty(symbol,amount);
	if (target)
        
		this->modifyMonsterAttributes[attribute] = skillProperty;
	else
		this->modifySelfAttributes[attribute] = skillProperty;
}


Skill::Skill(vector<pair<string,SingleSkill>> setOfSkills)
{
	for (pair<string,SingleSkill> currentSkill:setOfSkills)
	{
		this->AddSkill(currentSkill);
	}
}

int Skill::AddSkill(pair<string,SingleSkill> oneSkill)
{
	this->skillLibrary.push_back(oneSkill);
    return this->skillLibrary.size()-1;
}


string Skill::toString() const
{
    return "stub";
}