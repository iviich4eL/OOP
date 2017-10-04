#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cstdlib>
#include <iostream>
#include "Figure.h"

using std::ostream;
using std::istream;

class Triangle : public Figure
{
private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
    size_t square;

public:
    Triangle();
    Triangle(size_t i, size_t j, size_t k);
    Triangle(const Triangle & tr);
    void ErrorInSquare();

    double Square() override;
    void Print() override;
    virtual ~Triangle();

    Triangle & operator=(const Triangle & tr);

    friend bool operator==(const Triangle & left,const Triangle & right);
    friend bool operator>(const Triangle & left,const Triangle & right);
    friend bool operator<(const Triangle & left,const Triangle & right);
    friend ostream & operator<<(ostream & os, Triangle & tr);
    friend istream & operator>>(istream & os, Triangle & tr);
};

#endif /* TRIANGLE_H */
