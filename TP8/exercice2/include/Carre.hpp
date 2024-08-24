#ifndef _CARRE_HPP
#define _CARRE_HPP

#include "Rectangle.hpp"
#include "Losange.hpp"

class Carre : public Rectangle, public Losange {
public:
    Carre(const std::string& name, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3, const Vecteur& p4);
    
    void test() const override;

    friend std::ostream& operator<<(std::ostream& os, const Carre& c);
};

#endif
