#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include "Quadrilatere.hpp"

class Rectangle : virtual public Quadrilatere {
public:
    Rectangle(const std::string& nom, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3, const Vecteur& p4);
    
    void test() const override;

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);
};

#endif
