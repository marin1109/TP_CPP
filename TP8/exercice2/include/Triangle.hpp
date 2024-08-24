#ifndef _TRIANGLE_HPP
#define _TRIANGLE_HPP

#include <iostream>
#include "Figure.hpp"

class Triangle : public Figure {
private:
    Vecteur p1, p2, p3;

public:
    Triangle(const std::string& name, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3);
    
    void perimeter() const override;
    double area() const override;
    void test() const override;

    friend std::ostream& operator<<(std::ostream& os, const Triangle& t);
};

#endif 
