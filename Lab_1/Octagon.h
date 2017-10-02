#ifndef OCTAGON_H
#define OCTAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Octagon : public Figure
{
public:
  Octagon();
  Octagon(size_t i);
  Octagon(std::istream &is);
  Octagon(const Octagon &orig);

  double Octagon() override;
  void Print() override;

  virtual ~Octagon();

private:
  size_t side_a;
};

#endif