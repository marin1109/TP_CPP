#include "../include/Carre.hpp"

Carre::Carre(const std::string& name, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3, const Vecteur& p4) :Quadrilatere(name, p1, p2, p3, p4), Rectangle(name, p1, p2, p3, p4), Losange(name, p1, p2, p3, p4) {
}

void Carre::test() const {
    std::cout << "Test of Carre " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Carre& c) {
    os << "Carre " << c.name << " with points (" << c.p1 << ", " << c.p2 << ", " << c.p3 << ", " << c.p4 << ")";
    return os;
}
