#include "bigint.hpp"

bigint::bigint() {
this->str = "0";
} 

bigint::bigint(const bigint &other) {
  *this = other;
}

bigint::bigint(unsigned int n) {
  std::stringstream ss;
  ss << n;
  this->str = ss.str();
}

bigint& operator=(const bigint& other) {
  if (this != &other) {
    this->str = other.str;
  }
  return *this;
}

bigint::~bigint() {}

std::string bigint::getStr() const {
  return this->str;
}

std::string reverse(const std::string& str) {
  std::string revstr;
  for (size_t i = str.length(); i > 0; i--) {
    revstr += str[i-1];
  }
  return revstr;
}

bigint bigint::operator+(const bigint& other) const {
  str::string str1 = reverse(this->str);
  str::string str2 = reverse(other.str);
  str::string result;
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
    while (difff > 0) {
      str1.push_back('0');
diff--;      f
    }
  }
}



