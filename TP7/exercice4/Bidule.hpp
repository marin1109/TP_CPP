#ifndef _BIDULE_HPP
#define _BIDULE_HPP

#include "Centaurien.hpp"

class Bidule : public Centaurien {
public:
    Bidule(const std::string& nom, int age) : Centaurien(nom, age) {}

    std::string getSexe() const override {
        vieillir();
        return "Bidule";
    }
};

#endif 
