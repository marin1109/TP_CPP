#include "../include/Rectangle.hpp"

Rectangle::Rectangle(const std::string& nom, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3, const Vecteur& p4) : Quadrilatere(nom, p1, p2, p3, p4) {}

void Rectangle::test() const {
    std::cout << "Test of Rectangle " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    os << "Rectangle " << r.name << " with points (" << r.p1 << ", " << r.p2 << ", " << r.p3 << ", " << r.p4 << ")";
    return os;
}