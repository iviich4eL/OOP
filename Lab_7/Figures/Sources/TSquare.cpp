#include "../Headers/TSquare.h"
#include <cmath>

const int TSQUARE = 3;

TSquare::TSquare(): TSquare(0) {
}
TSquare::TSquare(size_t number) {
    side_a = number;
    type = TSQUARE;
//    std::cout << "Square created: "
//              << side_a << std::endl;
}
TSquare::TSquare(const TSquare & sq) {
    side_a = sq.side_a;
    type = TSQUARE;
}

void TSquare::Print() {
    std::cout << "s:";
    std::cout << *this;
}
double TSquare::Square() {
    return (side_a * side_a);
}
TSquare::~TSquare() {
//    std::cout << "Square deleted " << std::endl;
}

TSquare & TSquare::operator=(const TSquare & sq) {
    if (this == &sq) {
        return *this;
    } else {
        side_a = sq.side_a;
        return *this;
    }
}



void * TSquare::operator new(size_t size) {
    return Figure::figure_allocator.allocate();
}

void TSquare::operator delete(void * p) {
    Figure::figure_allocator.deallocate(p);
}

ostream & operator<<(ostream & os, TSquare & sq) {
    std::cout << sq.Square();
    return os;
}
istream & operator>>(istream & is, TSquare & sq) {
    is >> sq.side_a;
    return is;
}
