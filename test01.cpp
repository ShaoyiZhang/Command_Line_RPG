#include "Item.h"
#include "Bag.h"

#include <iostream>
#include "tddFuncs.h"
#include <vector>
using namespace std;

int main() {
  cout << "Running tests from: " << __FILE__ << endl;

  //int myAttr[] = {1,3,4};
  //vector<int> modifyAttr (myAttr, myAttr + sizeof(myAttr) / sizeof(int) );

  Item::Item foo("Ex-Calibur","Sword owned by King Arthur", 99999, 100,10);

  ASSERT_EQUALS("Ex-Calibur            10          100",foo.ToString());
 // ASSERT_EQUALS("bar",WordCount::stripWord("bar?"));
 // ASSERT_EQUALS("fum",WordCount::stripWord("...fum***"));
 // ASSERT_EQUALS("quote",WordCount::stripWord("\"quote\""));
 // ASSERT_EQUALS("isn't",WordCount::stripWord("isn't"));
 // ASSERT_EQUALS("mother-in-law",WordCount::stripWord("mother-in-law"));


  return 0;
}


