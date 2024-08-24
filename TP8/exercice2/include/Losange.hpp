#ifndef _LOSANGE_HPP
#define _LOSANGE_HPP

#include "Quadrilatere.hpp"

class Losange : virtual public Quadrilatere {
public:
    Losange(const std::string name, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3, const Vecteur& p4);
    
    void test() const override;

    friend std::ostream& operator<<(std::ostream& os, const Losange& l);
};

#endif
