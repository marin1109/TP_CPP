#ifndef _MACHIN_HPP
#define _MACHIN_HPP

#include "Centaurien.hpp"

class Machin : public Centaurien {
public:
    Machin(const std::string& nom, int age) : Centaurien(nom, age) {}

    std::string getSexe() const override {
        vieillir();
        return "Machin";
    }
};

#endif
