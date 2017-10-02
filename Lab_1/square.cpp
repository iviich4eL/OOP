#include "Square.h"
#include <iostream>
#include <cmath>

Square::Square()
{    
    side_a = 0;
} 

Square::Square(size_t i)
{
    side_a = i;
    std::cout << "Square created: "
              << side_a << std::endl;
}

void Square::Print()
{
    std::cout << "a = " << side_a  << std::endl;
}

double Square::Square()
{
    return (side_a * side_a);
}

Square::Square(std::istream &is)
{
    is >> side_a;
}

Square::~Square()
{
    std::cout << "Square deleted " << std::endl; 
}