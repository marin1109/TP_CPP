#ifndef _QUADRILATERE_HPP
#define _QUADRILATERE_HPP

#include <iostream>
#include "Figure.hpp"

class Quadrilatere : public Figure {
protected:
    Vecteur p1, p2, p3, p4;

public:
    Quadrilatere(const std::string& name, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3, const Vecteur& p4);
    
    void perimeter() const override;
    double area() const override;
    void test() const override;

    friend std::ostream& operator<<(std::ostream& os, const Quadrilatere& q);
};

#endif
