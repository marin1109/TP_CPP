#ifndef _TRUC_HPP
#define _TRUC_HPP

#include "Centaurien.hpp"

class Truc : public Centaurien {
public:
    Truc(const std::string& nom, int age) : Centaurien(nom, age) {}

    std::string getSexe() const override {
        vieillir();
        return "Truc";
    }
};

#endif
