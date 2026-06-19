#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int x, int y) : x(x), y(y) {}

vect2::vect2(const vect2& other) {
  *this = other;
}

vect2& vect2::operator=(const vect2& other) {
  if (this != &other)
  {
    this->x = other.x;
    this->y = other.y;
  }
  return *this;
}

vect2::~vect2() {}

int vect2::operator[](int index) const {
  if (index == 0)
    return x;
  return y;
}

int vect2::operator[](int index) const {
  if (index == 0)
    return x;
  return y;
}

int& vect2::operator[](int index) {
  if (index == 0)
    return x;
  return y;
}

vect2 vect2::operator-() const {
  vect2 tmp = *this;
  tmp[0] = -tmp[0];
  tmp[1] = -tmp[1];

  return tmp;
}

vect2 vect2::operator*(int num) const {
  vect2 tmp;
  tmp.x = this->x * num;
  tmp.y = this->y * num;
  return tmp;
}

vect2& vect2::operator*=(int num) {
  this->x *= num;
  this->y *= num;
  return *this;
}

vect2  vect2::operator-(const vect2& other) const {
  vect2 tmp;
  tmp.x = this->x - other.x;
  tmp.y = this->y - other.y;
  return tmp;
}

vect2 vect2::operator+(const vect2& other) const {
  vect2 tmp;

  tmp.x = this->x + other.x;
}
