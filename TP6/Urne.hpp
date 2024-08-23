#ifndef _URNE_HPP
#define _URNE_HPP

#include "Scrutin.hpp"
#include "ChoixVote.hpp"
#include <vector>

class Scrutin;

class Urne{
private:
    Urne(const Scrutin& scrutin);
    ~Urne();

    static int compteur;
    const Scrutin& scrutin;
    int numBureau;
    std::vector<int> votes;

public:
    bool voter(ChoixVote choix);

    int getId() const;
    int getNbVotes(int choix) const;

    void afficherResultats() const;

    friend class Scrutin;
};

#endif
