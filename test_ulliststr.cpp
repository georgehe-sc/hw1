#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;

  dat.push_back("test");
  std::cout << dat.get(0) << std::endl;
  dat.pop_back();

  dat.push_back("test");
  
  


  
  dat.show();
  
}
