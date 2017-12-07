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
    int type;

public:
    explicit Triangle();
    explicit Triangle(size_t i);
    Triangle(const Triangle & tr);

    double Square() override;
    int Type() override { return type; };
    void Print() override;
    virtual ~Triangle();

    Triangle & operator=(const Triangle & tr);

    friend ostream & operator<<(ostream & os, Triangle & tr);
    friend istream & operator>>(istream & os, Triangle & tr);
};

#endif /* TRIANGLE_H */
