#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>


class bigint {
private:
  std::string str;

public:
  bigint();
  bigint(const bigint& other);
  bigint(unsigned int n);
  bigint& operator=(const bigint& other);
  ~bigint();

  std::string getStr() const;

  // addition
  bigint operator+(const bigint& other) const;
  bigint& operator+=(const bigint& other);

  // increment
  bigint& operator++();
  bigint operator++(int);

  // shift with num
  bigint operator<<(unsigned int num) const;
  bigint operator>>(unsigned int num) const;
  bigint& operator<<=(unsigned int num);
  bigint& operator>>=(unsigned int num);

  //shift with object
  bigint operator>>(const bigint& other) const;
  bigint operator<<(const bigint& other) const;
  bigint& operator>>=(const bigint& other);
  bigint& operator<<=(const bigint& other);

  // != | == | < | > | <= | >=
  bool operator!=(const bigint& other) const;
  bool operator==(const bigint& other) const;
  bool operator<(const bigint& other) const;
  bool operator>(const bigint& other) const;
  bool operator<=(const bigint& other) const;
  bool operator>=(const bigint& other) const;

};

std::ostream& operator<<(std::ostream& output, const bigint& obj);

#endif // !BIGINT_HPP
