#ifndef _FRACTION_HPP
#define _FRACTION_HPP

#include <iostream>

class Fraction {
private:
    int num;
    int den;

    int pgcd(int x, int y){
        if (x < 0) return pgcd(-x, y);
        if (y < 0) return pgcd(x, -y);
        if (x == 0) return y;
        if (x > y) return pgcd(y, x);
        return pgcd(x, y - x);
    }

public:
    Fraction(int num, int den = 1) : num(num), den(den) {
        if (den == 0) {
            throw std::invalid_argument("Le dénominateur ne peut pas être nul");
        }

        int div = pgcd(num, den);
        this->num /= div;
        this->den /= div;

        if (this->den < 0) {
            this->num = -this->num;
            this->den = -this->den;
        }
    }

    ~Fraction() = default;
    Fraction(const Fraction&) = default;
    Fraction& operator=(const Fraction&) = default;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.num;
        if (f.den != 1) 
            os << '/' << f.den;
            
        return os;
    }

    // Fraction + int
    friend Fraction operator+(const Fraction& f, int i) {
        return f + Fraction(i, 1);
    }

    // int + Fraction
    friend Fraction operator+(int i, const Fraction& f) {
        return Fraction(i, 1) + f;
    }

    // Fraction - int
    friend Fraction operator-(const Fraction& f, int i) {
        return f - Fraction(i, 1);
    }

    // int - Fraction
    friend Fraction operator-(int i, const Fraction& f) {
        return Fraction(i, 1) - f;
    }

    // Surcharge des opérateurs + et - avec Fraction et Fraction
    Fraction operator+(const Fraction& f) const {
        return Fraction(num * f.den + f.num * den, den * f.den);
    }

    Fraction operator-(const Fraction& f) const {
        return Fraction(num * f.den - f.num * den, den * f.den);
    }
};

#endif
