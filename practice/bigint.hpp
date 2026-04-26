#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <vector>

class Bigint {
private:
  std::string bigint;

public:
  Bigint();
  Bigint(Bigint& other);
  Bigint& operator=(Bigint& other);
  ~Bigint();

  void bigInt();
};

#endif // !BIGINT_HPP
