#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  // test case 1: push 2, pop 1, get value at 0

  ULListStr dat;

  dat.push_back("test");
  dat.push_back("test 2");
  dat.pop_back();

  // expecting test
  std::cout << dat.get(0) << std::endl;
  dat.pop_back();
  

  // test case 2: push back 1, push front 2, get value at 1 (expect first push front)

  ULListStr dat2;

  dat2.push_back("Test");
  dat2.push_front("Test1");
  dat2.push_front("test2");

  // expect Test1
  std::cout << dat2.get(1) << std::endl;



  // test case 3: pop from null list;

  ULListStr dat3;
  dat3.pop_front();

  // expecting no error
  
}
