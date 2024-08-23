#include "ProtoProjet.hpp"

ProtoProjet::ProtoProjet() {
    taches = std::vector<std::unique_ptr<Tache>>();
    taches.push_back(std::make_unique<Tache>("Fin", 10));
    taches.push_back(std::make_unique<Tache>("Debut", 10));
}

ProtoProjet::~ProtoProjet() {}

bool ProtoProjet::ajoute(const std::string& nom, int duree) {
    if (taches.empty()) {
        taches.push_back(std::make_unique<Tache>(nom, duree));
        return true;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, taches.size() - 1);

    int index = dis(gen);
    taches.insert(taches.begin() + index, std::make_unique<Tache>(nom, duree));
    
    return true;
}

bool ProtoProjet::ajoute(const std::string& nom, int duree, int idTache) {
    for (const auto& tache : taches) {
        if (tache->getIdTache() == idTache) {
            taches.push_back(std::make_unique<Tache>(nom, duree));
            return true;
        }
    }
    return false;
}

bool ProtoProjet::ajoute(const std::string& nom, int duree, int Tache1, int Tache2) {
    Tache* tache1 = nullptr;
    Tache* tache2 = nullptr;

    for (const auto& tache : taches) {
        if (tache->getIdTache() == Tache1) {
            tache1 = tache.get();
        }
        if (tache->getIdTache() == Tache2) {
            tache2 = tache.get();
        }
        if (tache1 && tache2) {
            taches.push_back(std::make_unique<Tache>(nom, duree));
            // Si vous devez établir des dépendances, vous pouvez le faire ici
            return true;
        }
    }
    return false;
}

const std::vector<std::unique_ptr<Tache>>& ProtoProjet::getTaches() const {
    return taches;
}


void ProtoProjet::cleanMarks() {
    for (auto& tache : taches) {
        tache->mark_ = false;
    }
}

void ProtoProjet::topologicalSort() {
    cleanMarks();
    std::vector<Tache*> tachesTriees;
    for (const auto& tache : taches) {
        tache->PP_postfixe(tachesTriees);
    }
    
    std::vector<std::unique_ptr<Tache>> tachesTrieesUnique;
    for (Tache* tache : tachesTriees) {
        tachesTrieesUnique.push_back(std::make_unique<Tache>(*tache));
    }

    taches = std::move(tachesTrieesUnique);
}

std::ostream& operator<<(std::ostream& os, const ProtoProjet& protoProjet) {
    for (const auto& tache : protoProjet.taches) {
        os << *tache << std::endl;
    }
    return os;
}
