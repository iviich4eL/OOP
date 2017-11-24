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
    int type;

public:
    explicit Octagon();
    explicit Octagon(size_t number);
    Octagon(const Octagon & oct);

    double Square() override;
    int Type() override { return type; };
    void Print() override;
    virtual ~Octagon();

    Octagon & operator=(const Octagon & oct);

    void* operator new(size_t size);
    void operator delete (void * p);

    friend ostream & operator<<(ostream & os, Octagon & oct );
    friend istream & operator>>(istream & is, Octagon & oct );
};

#endif /* OCTAGON_H */