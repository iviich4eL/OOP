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

public:
    Triangle();
    Triangle(size_t i);
    Triangle(const Triangle & tr);

    double Square() override;
    void Print() override;
    virtual ~Triangle();

    Triangle & operator=(const Triangle & tr);

    friend ostream & operator<<(ostream & os, Triangle & tr);
    friend istream & operator>>(istream & os, Triangle & tr);
};

#endif /* TRIANGLE_H */
