#ifndef VECT2
#define VECT2

#include <cmath>


class Vect2 {
  private:
    int x;
     int y;
  public:
    Vect2();
    vect2(int x, int y);
    vect2(const vect2& v);
    vect2& operator=(const vect2& v);

    operator+(const vect2& v) const;
    operator-(const vect2& v) const;
    operator*(const vect2& v) const;
    operator/(const vect2& v) const;
}

#endif // !VECT2
