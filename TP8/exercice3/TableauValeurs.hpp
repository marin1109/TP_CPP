#ifndef _TABLEAUVALEURS_HPP
#define _TABLEAUVALEURS_HPP

#include "ValeursAdmises.hpp"

class TableauValeurs: public ValeursAdmises {
private:
    const char* tab;
    int length;

public:
    TableauValeurs(const char* tab, int length) : tab(tab), length(length) {}

    bool operator()(char val) const override {
        for (int i = 0; i < length; i++) {
            if (tab[i] == val) {
                return true;
            }
        }
        return false;
    }
};

#endif
