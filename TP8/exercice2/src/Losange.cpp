#include "../include/Losange.hpp"

Losange::Losange(const std::string name, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3, const Vecteur& p4) : Quadrilatere(name, p1, p2, p3, p4) {}

void Losange::test() const {
    std::cout << "Test of Losange " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Losange& l) {
    os << "Losange " << l.name << " with points (" << l.p1 << ", " << l.p2 << ", " << l.p3 << ", " << l.p4 << ")";
    return os;
}