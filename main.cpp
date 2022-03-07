#include <iostream>
#include "HugeInt.h"

int main(){

  HugeInt a= HugeInt("1234454");
  HugeInt b = HugeInt(1626236);
  std::cout << (a + b).v << std::endl;
  std::cout << (a * b).v << std::endl;
  return 0;
}
