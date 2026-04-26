#include "bigint.hpp"

Bigint::Bigint() {
  this->str = "0";
};

Bigint::Bigint(const Bigint& other) {
  (*this) = other;
};

Bigint::Bigint(unsigned int n) {
  std::stringstream ss;
  ss << n;
  this->str = ss.str();
}

Bigint& Bigint::operator=(const Bigint& other) {
  if (this != &other) {
    this->str = other.str;
  }
  return *this;
};

Bigint::~Bigint() {};

std::ostream& operator<<(std::ostream& ss, const Bigint& obj) {
  ss << obj.getStr();
  return ss;
}

std::string Bigint::getStr() const {
  return (this->str);
}

std::string reverse(const std::string& str) {
  std::string strRev;
  for (size_t i = str.length(); i > 0; i--) {
    strRev.push_back(str[i-1]);
  }
  return strRev;
}

// 1234 89 => 4321 98 => 4 2 => 4321 9800 =>

std::string addition(const Bigint& obj1, const Bigint& obj2) {
  std::string str1 = reverse(obj1.getStr());
  std::string str2 = reverse(obj2.getStr());
  std::string result;
  size_t len1 = str1.length();
  size_t len2 = str2.length();

  if (len1 > len2) {
    int diff = len1 - len2;
    while (diff > 0) {
      str2.push_back('0');
      diff--;
    }
  } else if (len2 > len1) {
    int diff = len2 - len1;
    while (diff > 0) {
      str1.push_back('0');
      diff--;
    }
  }
  int carry = 0;
  int digit1;
  int digit2;
  size_t len = str1.length();
  for (int i = 0; i < len; i++) {
    digit1 = str1[i] - '0';
    digit2 = str2[i] - '0';
    int res = digit1 + digit2 + carry;
    if (res > 9) {
      carry = res / 10;
      result.push_back((res % 10) + '0');
    } else {
      result.push_back(res + '0');
    }
  }
  if (carry != 0)
    result.push_back(carry + '0');

  return reverse(result);
}

Bigint Bigint::operator+(const Bigint& other) const {
  Bigint tmp(other);
  tmp.str.clear();
  std::string res = addition(*this, other);
  tmp.str = res;
  return tmp;
}

Bigint& Bigint::operator+=(const Bigint& other) {
  *this = *this + other;
  return *this;
}

Bigint& Bigint::operator++() {
  *this = *this + Bigint(1);
  return *this;
}

Bigint Bigint::operator++(int) {
  Bigint temp = *this;
  *this = *this + Bigint(1);
  return temp;
}

Bigint Bigint::operator<<(unsigned int num) {
  Bigint tmp = *this;
  tmp.str.insert(tmp.str.end(), n, '0');
  return tmp;
}

Bigint Bigint::operator>>(unsigned int num) {

}



