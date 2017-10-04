#ifndef OCTAGON_H
#define OCTAGON_H

#include <cstdlib>
#include <iostream>
#include "Figure.h"

using std::ostream;
using std::istream;

class Octagon : public Figure {
private:
    size_t side_a;
    size_t square;

public:
    explicit Octagon();
    explicit Octagon(size_t number);
    Octagon(const Octagon & oct);

    void ErrorInSquare();
    double Square() override;
    void Print() override;
    virtual ~Octagon();

    Octagon & operator=(const Octagon & oct);
    Octagon & operator=(const size_t number);
    friend bool operator==(const Octagon & left,const Octagon & right);
    friend bool operator>(const Octagon & left,const Octagon & right);
    friend bool operator<(const Octagon & left,const Octagon & right);

    friend ostream & operator<<(ostream & os, Octagon & oct );
    friend istream & operator>>(istream & is, Octagon & oct );
};

#endif /* OCTAGON_H */