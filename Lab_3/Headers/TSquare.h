#ifndef TSQUARE_H
#define TSQUARE_H

#include <cstdlib>
#include <iostream>
#include "Figure.h"

using std::ostream;
using std::istream;

class TSquare : public Figure {
private:
    size_t side_a;

public:
    explicit TSquare();
    explicit TSquare(size_t number);
    TSquare(const TSquare & sq);

    double Square() override;
    void Print() override;
    virtual ~TSquare();

    TSquare & operator=(const TSquare & sq);

    friend ostream & operator<<(ostream & os, TSquare & sq );
    friend istream & operator>>(istream & is, TSquare & sq );
};

#endif /* TSQUARE_H */
