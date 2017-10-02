#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle()
{
    side_a = side_b = side_c = 0;
}

Triangle::Triangle(size_t i, size_t j, size_t k)
{
    side_a = i;
    side_b = j;
    side_c = k;
    std::cout << "Triangle created: "
              << side_a << ", "
              << side_b << ", "
              << side_c << std::endl;
}

void Triangle::Print()
{
    std::cout << "a = " << side_a
              << " b = " << side_b
              << " c = " << side_c << std::endl;
}

double Triangle::Square()
{
    double p = double(side_a + side_b + side_c) / 2.0;
    return sqrt(p * (p - double(side_a)) * (p - double(side_b)) * (p - double(side_c)));
}

Triangle::Triangle(std::istream &is)
{
    is >> side_a;
    is >> side_b;
    is >> side_c;
}

Triangle::~Triangle()
{
    std::cout << "Triangle deleted " << std::endl;
}