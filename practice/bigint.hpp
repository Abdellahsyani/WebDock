#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>


class Bigint {
private:
  std::string str;

public:
  Bigint();
  Bigint(const Bigint& other);
  Bigint(unsigned int n);
  Bigint& operator=(const Bigint& other);
  ~Bigint();

  std::string getStr() const;

  // addition
  Bigint operator+(const Bigint& other) const;
  Bigint& operator+=(const Bigint& other);

  // increment
  Bigint& operator++();
  Bigint operator++(int);

  // shift with num
  Bigint operator<<(unsigned int num) const;
  Bigint operator>>(unsigned int num) const;
  Bigint& operator<<=(unsigned int num);
  Bigint& operator>>=(unsigned int num);

  //shift with object
  Bigint operator>>(const Bigint& other) const;
  Bigint operator<<(const Bigint& other) const;
  Bigint& operator>>=(const Bigint& other);
  Bigint& operator<<=(const Bigint& other);

  // != | == | < | > | <= | >=
  bool operator!=(const Bigint& other) const;
  bool operator==(const Bigint& other) const;
  bool operator<(const Bigint& other) const;
  bool operator>(const Bigint& other) const;
  bool operator<=(const Bigint& other) const;
  bool operator>=(const Bigint& other) const;

};

std::ostream& operator<<(std::ostream& output, const Bigint& obj);

#endif // !BIGINT_HPP
