#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Triangle : public Figure
{
  public:
    Triangle();
    Triangle(size_t i, size_t j, size_t k);
    Triangle(std::istream &is);
    Triangle(const Triangle &orig);

    double Square() override;
    void Print() override;

    virtual ~Triangle();

  private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
};

#endif