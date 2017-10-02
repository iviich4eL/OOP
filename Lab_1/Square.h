#ifndef SQUARE1_H_
#define SQUARE1_H_

#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Square : public Figure
{
  public:
    Square1();
    Square1(size_t i);
    Square1(std::istream &is);
    Square1(const Square1 &orig);

    // double Square() override;
    void Print() override;

    virtual ~Square();

  private:
    size_t side_a;
};

#endif