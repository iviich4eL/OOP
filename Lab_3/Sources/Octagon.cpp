#include "../Headers/Octagon.h"
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

double Octagon::Square() {
    return (2 * (1 + sqrt(2)) * pow(side_a,2));
}
void Octagon::Print() {
    std::cout << "o:";
    std::cout << *this;
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

ostream & operator<<(ostream & os, Octagon & oct) {
    std::cout << oct.Square();
    return os;
}
istream & operator>>(istream & is, Octagon & oct) {
    is >> oct.side_a;
    return is;
}