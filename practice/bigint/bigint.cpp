#include "bigint.hpp"

bigint::bigint() {
  this->str = "0";
}

bigint::bigint(const bigint& other) {
  this->str = other.str;
}

bigint& bigint::operator=(const bigint& other) {
  if (this != &other) {
    this->str = other.str;
  }
  return *this;
}

bigint::~bigint() {}

bigint::bigint(unsigned int num) {
  std::stringstream ss;
  ss << num;
  this->str = ss.str();
}

std::string reverse(const std::string& str) {
  std::string res = "";
  for (int i = str.size() - 1; i >= 0; i--) {
    res.push_back(str[i]);
  }
  return res;
}

bigint bigint::operator+(const bigint& other) const {
  std::string str1 = reverse(this->str);
  std::string str2 = reverse(other.str);
  int len1 = str1.length();
  int len2 = str2.length();
  int diff = 0;
  bigint tmp(*this);
  tmp.str.clear();

  if (len1 > len2) {
    diff = len1 - len2;
    while (diff > 0) {
      str2.push_back('0');
      diff--;
    }
  }
  if (len2 > len1) {
    diff = len2 - len1;
    while (diff > 0) {
      str1.push_back('0');
      diff--;
    }
  }
  // 1234 + 5670
  // 4321 + 0765
  std::string res;
  int size = str1.size();
  int u1 = 0, u2 = 0;
  int sum = 0;
  int carry = 0;
  for (int i = 0; i < size; i++) {
    u1 = str1[i] - '0';
    u2 = str2[i] - '0';
    sum = u1 + u2 + carry;
    if (sum > 9) {
      res.push_back(sum % 10 + '0');
      carry = sum / 10;
    }
    //24 
    //12
    //63
    else {
      res.push_back(sum + '0');
    }
  }
    if (carry != 0)
    {
      res.push_back(carry + '0');
    }
    
  tmp.str = reverse(res);
  return tmp;
}

bigint& bigint::operator+=(const bigint& other) {
  (*this) = (*this) + other;
  return *this;
}

bigint& bigint::operator++() {
  (*this) = (*this) + bigint(1);
  return *this;
}

bigint bigint::operator++(int) {
  bigint tmp(*this);
  (*this) = (*this) + bigint(1);
  return tmp;
}

bigint bigint::operator<<(unsigned int num) const {
 bigint tmp(*this);
  tmp.str.insert(tmp.str.end(),num,'0');
  return (tmp);
}

bigint bigint::operator>>(unsigned int num) const {
  bigint tmp(*this);
  tmp.str.erase(tmp.str.length() - num, num);
  return tmp;
}

bigint& bigint::operator>>=(unsigned int num) {
  *this = *this >> num;
  return *this;
}

bigint& bigint::operator<<=(unsigned int num) {
  *this = *this << num;
  return *this;
}

unsigned int touint(std::string str)
{
  unsigned int res;
  std::stringstream ss(str);
  ss >> res;
  return (res);
}

bigint bigint::operator>>(const bigint& other) const {
  bigint tmp(*this);
  tmp = (*this) >> touint(other.str);
  return tmp;
}

bigint bigint::operator<<(const bigint& other) const {
  bigint tmp(*this);
  tmp = tmp << touint(other.str);
  return tmp;
}

bigint& bigint::operator>>=(const bigint& other) {
  (*this) = (*this) >> touint(other.str);
  return *this;
}

bigint& bigint::operator<<=(const bigint& other) {
  *this = *this << touint(other.str);
  return *this;
}

bool bigint::operator==(const bigint& other) const {
  if (this->getStr() == other.getStr())
    return true;
  return false;
}

bool bigint::operator<(const bigint& other) const {
  std::string str1 = this->str;
  std::string str2 = other.getStr();
  int len1 = str1.length();
  int len2 = str2.length();

  if (len1 != len2)
    return (len1 < len2);
  return (str1 < str2);
}

bool bigint::operator>(const bigint& other) const {
  return other < *this;
}

bool bigint::operator!=(const bigint& other) const {
  return !(*this == other);
}

bool bigint::operator<=(const bigint& other) const {
  return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
  return !(*this < other);
}

std::string bigint::getStr() const {
  return this->str;
}

std::ostream& operator<<(std::ostream& os, const bigint& other) {
  os << other.getStr();
  return os;
}
