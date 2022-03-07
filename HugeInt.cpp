#include "HugeInt.h"

HugeInt::HugeInt(std::string value) {
  v = value;
}

HugeInt::HugeInt(int value) {
  v = std::to_string(value);
}

HugeInt HugeInt::operator + (const HugeInt & arg) const 
{ 
  int car = 0;
  std::string ans;
  int i = arg.v.size() - 1;
  int j = this->v.size() - 1;
  while (i >= 0 && j >= 0) {
    int digit_sum = (arg.v[i]-'0') + (this->v[j]-'0') + car;
    ans = std::to_string(digit_sum % 10) + ans;
    car = digit_sum / 10;
    i--;
    j--;
  }
  std::string head;
  int index;
  if(i >= 0) {
    head = arg.v;
    index = i;
  }
  else {
    head = this->v;
    index = j;
  }

  while(index != -1) {
    int sum = head[index]-'0'+ car;
    ans = std::to_string(sum%10) + ans;
    car = sum/10;
    index--;
  }
  if (car)
    ans = std::to_string(car) + ans;
  return HugeInt(ans);
}


HugeInt HugeInt ::operator * (const HugeInt & arg) const
{
  int car = 0;
  HugeInt mul_ans = HugeInt(0);
  int i = arg.v.size()-1;
  int j;
  std::string zeros;
  
  while (i >= 0) {
    std::string ans;
    j = this->v.size()-1;
    while (j >= 0) {
      int dig_mul = (arg.v[i]-'0')*(this->v[j]-'0') + car;
      ans = std::to_string(dig_mul%10) + ans;
      car = dig_mul/10;
      j--;
    }
    if (car){
      ans = std::to_string(car) + ans;
      car = 0;
    }
    ans += zeros;
    mul_ans = mul_ans + HugeInt(ans);
    zeros += "0";
    i--;
  }
  return mul_ans;
}
