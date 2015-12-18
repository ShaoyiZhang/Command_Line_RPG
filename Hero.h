#include "Life.h"
#include "Bag.h"

class Hero:public Life
{
private:
	int ownership;	// distinct value stored in World class, indicating Ownership
	int coin;
	int level;
	int experience;
	Bag bag;
public:
    bool CheckOwnership(item& item);
    bool CheckLevelUp();
    void UpdateLevel();   // might call CheckLevelUp()


}