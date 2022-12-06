#include <iostream>
#include "HugeInt.h"
 
int main() {
  //A little example
  HugeInt h;
  std::cin >> h;
  std::cout << h + h <<std::endl;
  std::cout << h - h <<std::endl;
  std::cout << h * h <<std::endl;
}
