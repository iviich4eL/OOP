#include "../Headers/Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(0, 0, 0) {
}
Triangle::Triangle(size_t i, size_t j, size_t k) {
    side_a = i;
    side_b = j;
    side_c = k;
    square = this->Square();
//    std::cout << "Triangle created: "
//              << side_a << ", "
//              << side_b << ", "
//              << side_c << std::endl;
}
Triangle::Triangle(const Triangle & tr) {
    side_a = tr.side_a;
    side_b = tr.side_b;
    side_c = tr.side_c;
}

void Triangle::ErrorInSquare() {
    if (this->Square() <= 0) {
        std::cout << "No such triangle!\nEnter another: " << std::endl;
        std::cin >> *this;
        this->ErrorInSquare();
    } else {
        return;
    }
}
void Triangle::Print() {
    std::cout << "a = " << side_a
              << " b = " << side_b
              << " c = " << side_c << std::endl;
}
double Triangle::Square() {
    double p = double(side_a + side_b + side_c) / 2.0;
    return  sqrt(p * (p - double(side_a)) * (p - double(side_b)) * (p - double(side_c)));
}
Triangle::~Triangle() {
    std::cout << "Triangle deleted " << std::endl;
}

Triangle & Triangle::operator=(const Triangle & tr) {
    if (this == &tr) {
        return *this;
    } else {
        side_a = tr.side_a;
        side_b = tr.side_b;
        side_c = tr.side_c;
        return *this;
    }
}

bool operator==(const Triangle & left, const Triangle & right) {
    return( left.square == right.square );
}
bool operator<(const Triangle & left,const Triangle & right) {
    return (left.square < right.square );
}
bool operator>(const Triangle & left,const Triangle & right) {
    return (left.square > right.square );
}

ostream & operator<<(ostream & os, Triangle & tr) {
    os << tr.side_a << ' ' << tr.side_b << ' ' << tr.side_c;
    tr.ErrorInSquare();
    return os;
}
istream & operator>>(istream & is, Triangle & tr) {
    is >> tr.side_a;
    is >> tr.side_b;
    is >> tr.side_c;
    return is;
}