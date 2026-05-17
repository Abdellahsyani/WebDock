#include "vect2.hpp"

// Constructors
vect2::vect2() : firstNum(0), secondNum(0) {}
vect2::vect2(int a, int b) : firstNum(a), secondNum(b) {}
vect2::vect2(const vect2 &other) { *this = other; }

// Assignment
vect2 &vect2::operator=(const vect2 &other) {
  if (this != &other) {
    firstNum = other.firstNum;
    secondNum = other.secondNum;
  }
  return *this;
}

// Destructor
vect2::~vect2() {}

// Access operators
int &vect2::operator[](int idx) { return (idx == 0) ? firstNum : secondNum; }
int vect2::operator[](int idx) const {
  return (idx == 0) ? firstNum : secondNum;
}

// Arithmetic operators
vect2 vect2::operator+(const vect2 &other) const {
  return vect2(firstNum + other.firstNum, secondNum + other.secondNum);
}
vect2 vect2::operator-(const vect2 &other) const {
  return vect2(firstNum - other.firstNum, secondNum - other.secondNum);
}
vect2 vect2::operator-() const { return vect2(-firstNum, -secondNum); }
vect2 vect2::operator*(int n) const {
  return vect2(firstNum * n, secondNum * n);
}

// Compound assignment
vect2 &vect2::operator+=(const vect2 &other) {
  firstNum += other.firstNum;
  secondNum += other.secondNum;
  return *this;
}
vect2 &vect2::operator-=(const vect2 &other) {
  firstNum -= other.firstNum;
  secondNum -= other.secondNum;
  return *this;
}
vect2 &vect2::operator*=(int n) {
  firstNum *= n;
  secondNum *= n;
  return *this;
}

// Increment / Decrement
vect2 vect2::operator++(int) {
  vect2 tmp = *this;
  ++*this;
  return tmp;
}
vect2 &vect2::operator++() {
  ++firstNum;
  ++secondNum;
  return *this;
}
vect2 vect2::operator--(int) {
  vect2 tmp = *this;
  --*this;
  return tmp;
}
vect2 &vect2::operator--() {
  --firstNum;
  --secondNum;
  return *this;
}

bool vect2::operator==(const vect2 &other) const {
  if (firstNum == other.firstNum && secondNum == other.secondNum)
    return true;
  return false;
}

bool vect2::operator!=(const vect2 &other) const {
  if (*this == other)
    return false;
  return true;
}

// Non-member operator for scalar * vector
vect2 operator*(int n, const vect2 &other) { return other * n; }

// Output
std::ostream &operator<<(std::ostream &out, const vect2 &other) {
  out << "{" << other.firstNum << ", " << other.secondNum << "}";
  return out;
}
