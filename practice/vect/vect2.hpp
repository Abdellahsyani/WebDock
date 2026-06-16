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
    vect2(const vect2& v);
    vect2& operator=(const vect2& v);
    ~vect2();

    int operator[](int num) const;
    int& operator[](int num);

    vect2 operator-() const; 
    vect2 operator*(int num) const;

    vect2& operator*=(int num);

    vect2& operator+=(const vect2& obj);
    vect2& operator-=(const vect2& obj);
    vect2& operator*=(const vect2& obj);

    vect2 operator+(const vect2& obj) const;
    vect2 operator-(const vect2& obj) const;
    vect2 operator*(const vect2& obj) const;

    vect2& operator++();
    vect2 operator++(int);
    vect2& operator--();
    vect2 operator--(int);

    bool operator==(const vect2& obj const);
    bool operator!=(const vect2& obj) const;
};

vect2 operator*(int num, const vect2& obj);
std::ostream& operator<<(std::ostream& os, const vect2& obj);


#endif // !VECT2
