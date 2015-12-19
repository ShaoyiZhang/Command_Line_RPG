#include "Item.h"


void Item::use()
{
    
}

bool Item::operator< (const Item &right) const
{
    return (this->buyInPrice < right.buyInPrice);
}