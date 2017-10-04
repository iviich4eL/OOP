#include "../Headers/Octagon.h"
#include <iostream>
#include <cmath>

Octagon::Octagon() : Octagon(0){
}
Octagon::Octagon(size_t number) {
    side_a = number;
//        std::cout << this << " octagon created: "
//                  << side_a << std::endl;
}
Octagon::Octagon(const Octagon & oct) {
    side_a = oct.side_a;
//        std::cout << this << " octagon copy created, adress: "
//                  << &oct << std::endl;
}

void Octagon::ErrorInSquare() {
    if (this->Square() <= 0) {
        std::cout << "No such Octagon!\nEnter another: " << std::endl;
        std::cin >> *this;
        this->ErrorInSquare();
    } else {
        return;
    }
}
double Octagon::Square() {
    return (2 * (1 + sqrt(2)) * pow(side_a,2));
}
void Octagon::Print() {
    std::cout << "a = " << side_a << std::endl;
}
Octagon::~Octagon() {
//        std::cout << this << " octagon deleted " << std::endl;
}

Octagon & Octagon::operator=(const Octagon & oct) {
    if (this == &oct) {
        return *this;
    } else {
        side_a = oct.side_a;
//            std::cout << " Octagon copied" << std::endl;
        return *this;
    }
}
Octagon & Octagon::operator=(const size_t number) {
    if (side_a == number) {
        return *this;
    } else {
        side_a = number;
//            std::cout << " Octagon copied" << std::endl;
        return *this;
    }
}
bool operator==(const Octagon & left, const Octagon & right) {
    return left.side_a == right.side_a;
}
bool operator<(const Octagon & left, const Octagon & right) {
    return left.side_a < right.side_a;
}
bool operator>(const Octagon & left, const Octagon & right) {
    return left.side_a > right.side_a;
}

ostream & operator<<(ostream & os, Octagon & oct) {
    os << oct.side_a;
    oct.ErrorInSquare();
    return os;
}
istream & operator>>(istream & is, Octagon & oct) {
    is >> oct.side_a;
    return is;
}