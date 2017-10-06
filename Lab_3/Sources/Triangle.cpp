#include "../Headers/Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(0) {
}
Triangle::Triangle(size_t i) {
    side_a = i;
}
Triangle::Triangle(const Triangle & tr) {
    side_a = tr.side_a;
}

double Triangle::Square() {
    double p = double(side_a + side_a + side_a) / 2.0;
    return  sqrt(p * (p - double(side_a)) * (p - double(side_a)) * (p - double(side_a)));
}
void Triangle::Print() {
    std::cout << "tr:";
    std::cout << this->Square();
}
Triangle::~Triangle() {
//    std::cout << "Triangle deleted " << std::endl;
}

Triangle & Triangle::operator=(const Triangle & tr) {
    if (this == &tr) {
        return *this;
    } else {
        side_a = tr.side_a;
        return *this;
    }
}

ostream & operator<<(ostream & os, Triangle & tr) {
    os << tr.side_a << ' ' << tr.side_a << ' ' << tr.side_a;
    return os;
}
istream & operator>>(istream & is, Triangle & tr) {
    is >> tr.side_a;
    return is;
}