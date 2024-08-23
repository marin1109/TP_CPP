#include "Consultant.hpp"

Consultant::Consultant() {}

Consultant::~Consultant() {}

std::pair<std::vector<int>, int> Consultant::avis(const RunProjet &runProjet) {
    std::vector<int> avis;
    int note = 0;
    for (const auto &tache : runProjet.getTaches()) {
        avis.push_back(tache->getIdTache());
        note += tache->getDuree();
    }
    return std::make_pair(avis, note);
}
