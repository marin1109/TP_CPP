#include "../include/Quadrilatere.hpp"

Quadrilatere::Quadrilatere(const std::string& name, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3, const Vecteur& p4) : Figure(name), p1(p1), p2(p2), p3(p3), p4(p4) {}

void Quadrilatere::perimeter() const {
    double p2p1 = (p2 - p1).norm();
    double p3p2 = (p3 - p2).norm();
    double p4p3 = (p4 - p3).norm();
    double p1p4 = (p1 - p4).norm();

    std::cout << "Perimeter of quadrilatere " << name << " is " << p2p1 + p3p2 + p4p3 + p1p4 << std::endl;
}

double Quadrilatere::area() const {
    double p2p1 = (p2 - p1).norm();
    double p3p2 = (p3 - p2).norm();
    double p4p3 = (p4 - p3).norm();
    double p1p4 = (p1 - p4).norm();

    double p = (p2p1 + p3p2 + p4p3 + p1p4) / 2;
    return std::sqrt((p - p2p1) * (p - p3p2) * (p - p4p3) * (p - p1p4));
}

void Quadrilatere::test() const {
    std::cout << "Test of quadrilatere " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Quadrilatere& q) {
    os << "Quadrilatere " << q.name << " with points (" << q.p1 << ", " << q.p2 << ", " << q.p3 << ", " << q.p4 << ")";
    return os;
}
