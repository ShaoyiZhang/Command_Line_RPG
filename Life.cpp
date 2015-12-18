#include "Life.h"

Life::Life(string name, int attack, int defense, int stamina, int intelligence,
	       int stun, int weak, int HP, int MP, int totalHP, int totalMP, vector<Skill> skills)
		  :name (name), attack(attack), defense(defense), stamina(stamina),
		   intelligence(intelligence), stun(stun), weak(weak), HP(HP), MP(MP),
           totalHP(totalHP), totalMP(totalMP), skills(skills)
{
}