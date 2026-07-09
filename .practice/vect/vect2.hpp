#ifndef VECT2
#define VECT2

#include <cmath>
#include <iostream>


class vect2 {
  private:
    int x;
    int y;

  public:
    vect2();
    vect2(int x, int y);
    vect2(const vect2& other);
    vect2& operator=(const vect2& other);
    ~vect2();

    int operator[](int index) const;
    int&  operator[](int index);

    vect2 operator-() const;
    vect2 operator*(int num) const;

    vect2& operator*=(int num);


    vect2 operator-(const vect2& other) const;
    vect2 operator+(const vect2& other) const;
    vect2 operator*(const vect2& other) const;

    vect2& operator-=(const vect2& other);
    vect2& operator+=(const vect2& other);
    vect2& operator*=(const vect2& other);

    vect2& operator++();
    vect2 operator++(int);
    vect2& operator--();
    vect2 operator--(int);

    bool operator==(const vect2& other);
    bool operator!=(const vect2& other);
};

vect2 operator*(int num, const vect2& other);
std::ostream& operator<<(std::ostream& os, const vect2& other);

#endif // !VECT2j
