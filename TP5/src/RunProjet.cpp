#include "RunProjet.hpp"

RunProjet::RunProjet(ProtoProjet& protoProjet) {
    // Copie des tâches en utilisant std::unique_ptr
    for (const auto& tache : protoProjet.getTaches()) {
        taches.push_back(std::make_unique<Tache>(*tache));
    }
}

const std::vector<std::unique_ptr<Tache>>& RunProjet::getTaches() const {
    return taches;
}

void RunProjet::run(int idTache) {
    for (const auto& tache : taches) {
        if (tache->getIdTache() == idTache) {
            if (tache->realise()) {
                return;
            }
            return;
        }
    }
}

void RunProjet::run(const std::vector<int>& idTaches) {
    for (int idTache : idTaches) {
        run(idTache);
    }
}

std::ostream& operator<<(std::ostream& os, const RunProjet& runProjet) {
    for (const auto& tache : runProjet.taches) {
        if (tache) {
            os << *tache << " ";
        }
    }
    return os;
}
