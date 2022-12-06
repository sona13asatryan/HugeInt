#include <iostream>
#include <string>
#include "HugeInt.h"

HugeInt::HugeInt(std::string v) {
  if (input_validation(v)) {
    positive = (v[0] != '-');
    if (!positive) {
        value = v.substr(1, v.size() - 1);
    } else {
      value = v;
    }
  }
 
}

HugeInt::HugeInt(int v) {
  positive = (v >= 0);
  value = "";
  if (!positive) {
    v *= -1;
  }
  while(v != 0) {
    value = std::to_string(v%10) + value ;
    v /= 10;
  }
}

std::string HugeInt::summing (std::string a, std::string b) const {
  std::string result = "";
  int x,y,z;
  bool carry = 0;
  int sum;
  if (a.size() > b.size()) {
    for (int i = a.size() - b.size(); i > 0; i--) {
      b = '0' + b;
    }
  }
  else if (b.size() > a.size()) {
    for (int i = b.size() - a.size(); i > 0; i--) {
      a = '0' + a;
    }
  }

  for (int i = a.size() - 1 ; i >= 0; i--) {
    x = a[i] - '0';
    y = b[i] - '0';
    z = x + y + carry;
    sum = z%10;
    carry = z/10; 
    result = std::to_string(sum)  + result;
  }
  if (carry) {
      result = '1'+ result;
    }
    return result;
}

std::string HugeInt::subtracting (std::string a, std::string b) const {
  std::string result = "";
  int x,y,z;
  bool credit = 0;
  bool negative_result = 0;
  if (a.size() > b.size()) {
    for (int i = a.size() - b.size(); i > 0; i--) {
      b = '0' + b;
    }
  } else {
    for (int i = b.size() - a.size(); i > 0; i--) {
      a = '0' + a;
    }
  }
  if (b > a) {
    negative_result = 1;
    std::string str_temp = a;
    a = b;
    b = str_temp;
  }
  for (int i = a.size() - 1; i > 0; i--) {
    x = a[i] - '0';
    y = b[i] - '0';
    if (x - credit < y ) {
      z = 10 + x - y - credit;
      credit = 1;
      result = std::to_string(z) + result;
    }
    else {
      z = x - y - credit;
      credit = 0;   
      result = std::to_string(z) + result;
    }
    int j = 0;
    while (result[j] == '0') {
      j++;
    }
    if (j == result.size()) {
      return "0";
    }
    result = result.substr(j, result.size() - j + 1);
    if (negative_result) {
      result = '-' + result;
    }
  }
  return result;
}

std::string HugeInt::multiplicating (std::string a, char b) const {
  std::string y = "";
  int x;
  int carry = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    x = (b-'0') * (a[i]-'0') + carry;
    y = std::to_string(x%10) + y;
    carry = x/10;
  } 
  if (carry) {
    y = std::to_string(carry) + y;
  }
  return y;
}

std::ostream & operator << (std::ostream &out, const HugeInt &h)
{
  if (h.positive) {
    out << h.value;
    return out;
  } else {
    out << "-" << h.value;
    return out;
  }
}

std::istream & operator >> (std::istream &in, HugeInt &h) {
  std::string input;
  in >> input;
  h = HugeInt(input);
  return in;
}

HugeInt HugeInt:: operator + (const HugeInt & arg) const  {
  HugeInt temp;
  if (!(this->positive) && !(arg.positive)) {
    temp.value = summing(this->value, arg.value);
    temp.positive = false; 
  } else if ((this->positive) && (arg.positive)) {
    temp.value = summing(this->value, arg.value); 
    temp.positive = true; 
  } else {
    std::string t;
    if(!arg.positive) {
      t = subtracting(this->value, arg.value);
    } else {
      t = subtracting(arg.value, this->value);
    }
    if (t[0] == '-') {
      temp.value = t.substr(1, t.size()-1);
      temp.positive = false; 
    }
    else {
      temp.value = t;
      temp.positive = true;
    }
  }
  return temp;
}

HugeInt HugeInt:: operator - (const HugeInt & arg) const {
  HugeInt temp;
  temp.value = arg.value;
  temp.positive = !arg.positive;
  return *this + temp;
}

HugeInt HugeInt:: operator * (const HugeInt & arg) const {

  HugeInt temp;
  if (this->value == "0" || arg.value == "0") {
    return temp; // See default constructor
  }
  std::string zeros = "";
  if (arg.positive != this->positive) {
    temp.positive = false;
  }
  for (int j = arg.value.size() - 1; j >=0; j--) { 
    temp.value = summing(temp.value, multiplicating(this->value, arg.value[j]) + zeros);
    zeros += '0';
  }
  return temp;
}

void HugeInt::operator = (const HugeInt & arg) {
  this->value = arg.value;
  this->positive = arg.positive;
  return;
}

bool HugeInt::input_validation (std::string number) {
  if (number[0] != '-' || number[0] < '0' || number[0] > '9') {
    std::cerr << "Your input is not a number! Please try again!\n";
    std::abort();
  }
  for (int i = 1; i < number.size(); i ++) {
    if (number[0] < '0' || number[0] > '9') {
      std::cerr << "Your input is not a number! Please try again!\n";
      std::abort();
    }
  }
  return true;
}