#include "Projet.hpp"
#include <random>

using namespace std;

Projet::Projet(string nom) : nom(nom) {}

Projet::~Projet() {
    for (Tache* tache : taches) {
        delete tache; // Assurez-vous que les tâches sont allouées dynamiquement
    }
}

std::pair<int, int> Projet::pick_two_random_tasks() {
    if (taches.size() < 2) {
        return std::make_pair(-1, -1); // Pas assez de tâches pour choisir deux différentes
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, taches.size() - 1);
    
    int firstIndex = dis(gen);
    int secondIndex;
    do {
        secondIndex = dis(gen);
    } while (secondIndex == firstIndex);

    return std::make_pair(firstIndex, secondIndex);
}

Tache* Projet::contains(int idTache) const {
    for (Tache* tache : taches) {
        if (tache->getIdTache() == idTache) {
            return tache;
        }
    }
    return nullptr;
}

Tache* Projet::contains(const string nomTache) const {
    for (Tache* tache : taches) {
        if (tache->getNom() == nomTache) {
            return tache;
        }
    }
    return nullptr;
}

const vector<Tache*>& Projet::getTaches() const {
    return taches;
}

void Projet::topologicalSort() {
    // TODO: Implement
}
