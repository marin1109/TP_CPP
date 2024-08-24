#include "../include/Triangle.hpp"

Triangle::Triangle(const std::string& name, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3) : Figure(name), p1(p1), p2(p2), p3(p3) {}

void Triangle::perimeter() const {
    double a = (p1 - p2).norm();
    double b = (p2 - p3).norm();
    double c = (p3 - p1).norm();
    std::cout << "Perimeter of triangle " << name << " is " << a + b + c << std::endl;
}

double Triangle::area() const {
    double a = (p1 - p2).norm();
    double b = (p2 - p3).norm();
    double c = (p3 - p1).norm();
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::test() const {
    std::cout << "Test of triangle " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Triangle& t) {
    os << "Triangle " << t.name << " with points " << t.p1 << ", " << t.p2 << ", " << t.p3;
    return os;
}
