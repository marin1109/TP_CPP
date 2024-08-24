#ifndef INTERVALLE_HPP
#define INTERVALLE_HPP

#include "ValeursAdmises.hpp"

class Intervalle : public ValeursAdmises {
private:
    char min;
    char max;

public:
    Intervalle(char min, char max) : min(min), max(max) {}

    bool operator()(char val) const override {
        return val >= min && val <= max;
    }
};

#endif