#include Life.h

class Hero:public Life
{
private:
	int Ownership;	// distinct value stored in World class, indicating Ownership
	
public:
    bool checkOwnership(item& item);


}