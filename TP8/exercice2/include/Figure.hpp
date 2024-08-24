#ifndef _FIGURE_HPP
#define _FIGURE_HPP

#include <iostream>
#include "../../exercice1/Vecteur.hpp"

class Figure {
protected:
    std::string name;
public:
    Figure(const std::string& name) : name(name) {}

    virtual ~Figure() {}

    virtual void perimeter() const = 0;
    virtual double area() const = 0;
    virtual void test() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& f) {
        os << f.name;
        return os;
    }
};

#endif
