#include <string>

class HugeInt
{
public:
  HugeInt(std::string value);
  HugeInt(int value);
  HugeInt operator + (const HugeInt & arg) const;
  HugeInt operator * (const HugeInt & arg) const;
  std::string v;
};
