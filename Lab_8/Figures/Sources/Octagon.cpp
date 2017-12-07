#include "../Headers/Octagon.h"
#include <cmath>

const int OCTAGON = 1;

Octagon::Octagon() : Octagon(0){
}
Octagon::Octagon(size_t number) {
    side_a = number;
    type = OCTAGON;
}
Octagon::Octagon(const Octagon & oct) {
    side_a = oct.side_a;
}

double Octagon::Square() {
    return (2 * (1 + sqrt(2)) * pow(side_a,2));
}
void Octagon::Print() {
    std::cout << "o:";
    std::cout << *this;
}
Octagon::~Octagon() {
}

Octagon & Octagon::operator=(const Octagon & oct) {
    if (this == &oct) {
        return *this;
    } else {
        side_a = oct.side_a;
        return *this;
    }
}

ostream & operator<<(ostream & os, Octagon & oct) {
    std::cout << oct.Square();
    return os;
}
istream & operator>>(istream & is, Octagon & oct) {
    is >> oct.side_a;
    return is;
}