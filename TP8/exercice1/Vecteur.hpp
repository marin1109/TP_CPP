#ifndef _VECTEUR_HPP
#define _VECTEUR_HPP

#include <iostream>
#include <cmath>

class Vecteur {
private:
    double x, y;
public:
    Vecteur();
    Vecteur(double x, double y);
    ~Vecteur() = default;

    double norm() const;

    friend std::ostream& operator<<(std::ostream& os, const Vecteur& v);

    bool operator==(const Vecteur& v) const;
    bool operator!=(const Vecteur& v) const;

    Vecteur operator+(const Vecteur& v);
    const Vecteur operator+(const Vecteur& v) const { return Vecteur(x + v.x, y + v.y); }

    Vecteur operator-(const Vecteur& v);
    const Vecteur operator-(const Vecteur& v) const { return Vecteur(x - v.x, y - v.y); }

    double operator*(const Vecteur& v) const;
    
    double& operator[](int index) {
        if (index == 0) return x;
        else if (index == 1) return y;
        else throw std::out_of_range("Index out of range");
    }
    const double& operator[](int index) const {
        if (index == 0) return x;
        else if (index == 1) return y;
        else throw std::out_of_range("Index out of range");
    }

    Vecteur& operator=(const Vecteur& v) = default;
};

#endif
