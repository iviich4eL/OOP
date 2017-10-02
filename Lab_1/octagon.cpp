#include "Square.h"
#include <iostream>
#include <cmath>

Octagon::Octagon()
{    
    side_a = 0;
} 

Octagon::Octagon(size_t i)
{
    side_a = i;
    std::cout << "Octagon created: " << side_a << std::endl;
}

void Octagon::Print()
{
    std::cout << "a = " << side_a  << std::endl;
}

double Octagon::Octagon()
{
    return (side_a * side_a);
}

Octagon::Octagon(std::istream &is)
{
    is >> side_a;
}

Octagon::~Octagon()
{
    std::cout << "Square deleted " << std::endl; 
}