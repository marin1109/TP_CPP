#include "Expert.hpp"

Expert::Expert() {}

Expert::~Expert() {}

std::pair<std::vector<int>, int> Expert::avis(const RunProjet &run) {
    std::vector<int> avis;
    int note = 0;
    
    const std::vector<std::unique_ptr<Tache>>& taches = run.getTaches();

    int nombreTaches = taches.size();
    if (nombreTaches > 0) {
        for (const auto &tache : taches) {
            avis.push_back(tache->getIdTache());
            note += tache->getDuree();
        }
        note = note / nombreTaches;
    } else {
        note = 0;
    }

    return std::make_pair(avis, note);
}