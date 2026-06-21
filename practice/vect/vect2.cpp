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
  vect2 tmp = *this;
  tmp.x *= num;
  tmp.y *= num;
  return tmp;
}

vect2& vect2::operator*=(int num) {
  vect2 tmp = *this;
  this->x *= num;
  this->y *= num;
  return *this;
}

vect2 vect2::operator-(const vect2& other) const {
  vect2 tmp = *this;
  tmp.x -= other.x;
  tmp.y -= other.x;
  return tmp;
}

vect2 vect2::operator+(const vect2& other) const {
  vect2 tmp = *this;
  tmp.x += other.x;
  tmp.y += other.x;
  return tmp;
}

vect2 vect2::operator*(const vect2& other) const {
  vect2 tmp = *this;
  tmp.x *= other.x;
  tmp.y *= other.x;
  return tmp;
}

vect2& vect2::operator-=(const vect2& other) {
  this->x -= other.x;
  this->y -= other.x;
  return *this;
}

vect2& vect2::operator+=(const vect2& other) {
  this->x += other.x;
  this->y += other.x;
  return *this;
}

vect2& vect2::operator*=(const vect2& other) {
  this->x *= other.x;
  this->y *= other.x;
  return *this;
}

vect2& vect2::operator++() {
  this->x += 1;
  this->y += 1;
  return *this;
}

vect2 vect2::operator++(int) {
  vect2 tmp = *this;
  this->x += 1;
  this->y += 1;
  return tmp;
}

vect2& vect2::operator--() {
  this->x += 1;
  this->y += 1;
  return *this;
}

vect2 vect2::operator--(int) {
  vect2 tmp = *this;
  this->x += 1;
  this->y += 1;
  return tmp;
}

bool vect2::operator==(const vect2& other) {
  if (this->x == other.x && this->y == other.y)
    return true;
  return false;
}

bool vect2::operator!=(const vect2& other) {
  if (this->x != other.x || this->y != other.y)
    return true;
  return false;
}

vect2 operator*(int num, const vect2& other) {
  vect2 tmp(other);
  tmp *= num;
  return tmp;
}

std::ostream& operator<<(std::ostream& os, const vect2& other) {
  os << "{" << other[0] << ", " << other[1] << "}";
  return os;
}
