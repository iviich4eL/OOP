#include "../Headers/Triangle.h"
#include <iostream>
#include <cmath>

const int TRIANGLE = 2;

Triangle::Triangle() : Triangle(0) {
}
Triangle::Triangle(size_t i) {
    side_a = i;
    type = TRIANGLE;
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
    std::cout << *this;
}
Triangle::~Triangle() {
}

Triangle & Triangle::operator=(const Triangle & tr) {
    if (this == &tr) {
        return *this;
    } else {
        side_a = tr.side_a;
        return *this;
    }
}

void * Triangle::operator new(size_t size) {
    return Figure::figure_allocator.allocate();
}
void Triangle::operator delete(void * p) {
    Figure::figure_allocator.deallocate(p);
}

ostream & operator<<(ostream & os, Triangle & tr) {
    std::cout << tr.Square();
    return os;
}
istream & operator>>(istream & is, Triangle & tr) {
    is >> tr.side_a;
    return is;
}