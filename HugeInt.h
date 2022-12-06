#include <iostream>
class HugeInt
{
  public:
  HugeInt() {value = "0"; positive = 1;};
  HugeInt(std::string v);
  HugeInt(int v);
  HugeInt operator + (const HugeInt & arg) const;
  HugeInt operator - (const HugeInt & arg) const;
  HugeInt operator * (const HugeInt & arg) const;
  void operator = (const HugeInt & arg);
  friend std::ostream & operator << (std::ostream &out, const HugeInt &h);
  friend std::istream & operator >> (std::istream &in, HugeInt &h);

private:  
  std::string value;
  bool positive;
  std::string summing(std::string, std::string) const;
  std::string subtracting(std::string, std::string) const;
  std::string multiplicating (std::string, char) const;
  bool input_validation (std::string);
};

