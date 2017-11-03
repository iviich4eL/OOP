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

public:
    explicit Octagon();
    explicit Octagon(size_t number);
    Octagon(const Octagon & oct);

    double Square() override;
    void Print() override;
    virtual ~Octagon();

    Octagon & operator=(const Octagon & oct);

    friend ostream & operator<<(ostream & os, Octagon & oct );
    friend istream & operator>>(istream & is, Octagon & oct );
};

#endif /* OCTAGON_H */