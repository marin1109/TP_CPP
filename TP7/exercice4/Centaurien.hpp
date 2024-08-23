#ifndef _CENTAURIEN_HPP
#define _CENTAURIEN_HPP

#include <iostream>

class Centaurien {
private:
    const std::string nom;
    mutable int age;

protected:
    void vieillir() const {
        age++;
    }

public:
    Centaurien(const std::string& nom, int age) : nom(nom), age(age) {}

    std::string getNom() const {
        vieillir(); 
        return nom;
    }

    int getAge() const {
        vieillir();
        return age;
    }

    virtual std::string getSexe() const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Centaurien& c) {
        os << "Centaurien(" << c.nom << ", " << c.age << ")";
        return os;
    }
};

#endif
