#include "Urne.hpp"

int Urne::compteur = 0;

Urne::Urne(const Scrutin& scrut) : scrutin(scrut), numBureau(++compteur), votes(scrut.nbOptions, 0) {}


Urne::~Urne() {
    std::cout << "Destruction de l'urne du bureau numéro " << numBureau << std::endl;
}

bool Urne::voter(ChoixVote choix) {
    if (scrutin.estScrutinTermine()) {
        std::cout << "Le scrutin est terminé. Impossible de voter." << std::endl;
        return false;
    }
    switch (choix)
    {
    case ChoixVote::Oui:
        votes[0]++;
        break;
    case ChoixVote::Non:
        votes[1]++;
        break;
    case ChoixVote::VoteBlanc:
        votes[2]++;
        break;
    }
    return true;
}

int Urne::getId() const {
    return numBureau;
}

int Urne::getNbVotes(int choix) const {
    return votes[choix];
}

void Urne::afficherResultats() const {
    for (int i = 0; i < scrutin.nbOptions; ++i) {
        std::cout << "Option " << i << " : " << votes[i] << " voix" << std::endl;
    }
}
