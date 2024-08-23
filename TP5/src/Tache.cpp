#include "Tache.hpp"

int Tache::nbTaches_ = 0;

Tache::Tache(std::string nom, int duree) : nom_(nom), duree_(duree) {
    idTache_ = nbTaches_;
    nbTaches_++;
}

Tache::~Tache() {
    for (Tache* tache : dependances_) {
        tache->dependances_.erase(
            std::remove_if(tache->dependances_.begin(), tache->dependances_.end(), 
                [this](Tache* t) { return t == this; }), 
            tache->dependances_.end()
        );
    }
}

bool Tache::realise() {
    if (terminee_) {
        return false;
    }

    for (Tache* tache : dependances_) {
        if (!tache->terminee_) {
            return false;
        }
    }

    terminee_ = true;
    return true;
}

bool Tache::depends_from(const Tache& tache) {
    return std::find(dependances_.begin(), dependances_.end(), &tache) != dependances_.end();
}

bool Tache::ajouteDependance(Tache& tache) {
    if (tache.depends_from(*this)) {
        return false;
    }

    dependances_.push_back(&tache);
    return true;
}

int Tache::dureeParal() {
    int duree = 0;
    for (Tache* tache : dependances_) {
        duree = std::max(duree, tache->dureeParal());
    }

    return duree + duree_;
}

int Tache::getIdTache() const {
    return idTache_;
}

std::string Tache::getNom() const {
    return nom_;
}

int Tache::getDuree() const {
    return duree_;
}

bool Tache::getTerminee() const {
    return terminee_;
}

void Tache::setTerminee(bool terminee) {
    terminee_ = terminee;
}

void Tache::setDuree(int duree) {
    duree_ = duree;
}

void Tache::setNom(const std::string& nom) {
    nom_ = nom;
}

int Tache::getNbTaches() {
    return nbTaches_;
}

std::string afficheTermine(bool terminee) {
    return terminee ? "oui" : "non";
}

void Tache::run(int idTache) {
    for (int i = dependances_.size() - 1; i >= 0; --i) {
        if (dependances_[i]->getIdTache() == idTache) {
            if(dependances_[i]->realise()) {
                return;
            }
            return;
        }
    }
}

void Tache::PP_postfixe(std::vector<Tache*>& taches) {
    for (Tache* tache : dependances_) {
        tache->PP_postfixe(taches);
    }

    if (!mark_) {
        taches.push_back(this);
        mark_ = true;
    }
}

std::ostream& operator<<(std::ostream& os, const Tache& tache) {
    os << "Tache " << tache.nom_ << " (id: " << tache.idTache_ << ", duree: " << tache.duree_ << "s, terminee: " << afficheTermine(tache.terminee_) << ")";
    return os;
}

bool operator==(const Tache& tache1, const Tache& tache2) {
    return tache1.idTache_ == tache2.idTache_;
}

const Tache& Tache::operator=(const Tache& tache) {
    if (this != &tache) {
        nom_ = tache.nom_;
        idTache_ = tache.idTache_;
        terminee_ = tache.terminee_;
        duree_ = tache.duree_;
        dependances_ = tache.dependances_;
    }
    return *this;
}
