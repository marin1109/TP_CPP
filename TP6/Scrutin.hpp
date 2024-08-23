#ifndef SCRUTIN_HPP
#define SCRUTIN_HPP

#include <vector>
#include <iostream>

class Urne;  // Déclaration préalable de la classe Urne

class Scrutin {
private:
    int nbBureaux;
    int nbOptions;
    std::vector<Urne*> urnes;  // Tableau de pointeurs vers des urnes
    bool scrutinTermine = false;

public:
    Scrutin(int nbBureaux, int nbOptions);
    ~Scrutin();

    Urne& getUrne(int id) const;
    
    void afficherResultats() const;
    void afficherResultatsComplet() const;

    void terminerScrutin();
    bool estScrutinTermine() const;

    friend class Urne;
};

#endif
