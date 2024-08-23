#include "Scrutin.hpp"
#include "Urne.hpp"

Scrutin::Scrutin(int nbBureaux, int nbOptions) : nbBureaux(nbBureaux), nbOptions(nbOptions) {
    for (int i = 0; i < nbBureaux; ++i) {
        urnes.push_back(new Urne(*this));
    }
}

Scrutin::~Scrutin() {
    for (Urne* urne : urnes) {
        delete urne;
    }
    std::cout << "Destruction du scrutin" << std::endl;
}

Urne& Scrutin::getUrne(int id) const {
    return *urnes[id];
}

void Scrutin::terminerScrutin() {
    scrutinTermine = true;
}

bool Scrutin::estScrutinTermine() const {
    return scrutinTermine;
}

void Scrutin::afficherResultats() const {
    for (Urne* urne : urnes) {
        std::cout << "Bureau " << urne->getId() << " : ";
        urne->afficherResultats();
    }
}

void Scrutin::afficherResultatsComplet() const {
    for (Urne* urne : urnes) {
        urne->afficherResultats();
    }
}
