#include "Vecteur.hpp"

Vecteur::Vecteur(double x, double y) : x(x), y(y) {}

Vecteur::Vecteur() : x(0), y(0) {}

double Vecteur::norm() const {
    return std::sqrt(x * x + y * y);
}

std::ostream& operator<<(std::ostream& os, const Vecteur& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

bool Vecteur::operator==(const Vecteur& v) const {
    if (this == &v) {
        return true;
    }
    return x == v.x && y == v.y;
}

bool Vecteur::operator!=(const Vecteur& v) const {
    return !(*this == v);
}

Vecteur Vecteur::operator+(const Vecteur& v) {
    return Vecteur(x + v.x, y + v.y);
}

Vecteur Vecteur::operator-(const Vecteur& v) {
    return Vecteur(x - v.x, y - v.y);    
}

double Vecteur::operator*(const Vecteur& v) const {
    return x * v.x + y * v.y;
}
