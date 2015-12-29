#include "tddFuncs.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

void assertEquals(const char * const expected, 
		  const char * const actual, 
		  std::string message) {
  if ( !strcmp(expected,actual) ) {  // if they are equal
    cout << "PASSED: " << message << endl;
  } else {
    cout << "   FAILED: " << message << endl 
	 << "     Expected: " << expected << endl <<"   Actual: " << actual << endl;
  }
}

void assertEquals(const char * const expected, 
		  std::string actual, 
		  std::string message) {
  assertEquals(std::string(expected),actual,message);
}

void assertTrue(bool expression,
		  std::string message) {
  if (expression) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl 
	 << "     Expected true, but was false " << endl;
  }
}

