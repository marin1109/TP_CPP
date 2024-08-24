#ifndef _ENCHERE_HPP
#define _ENCHERE_HPP

#include "Observable.hpp"
#include <string>
#include <iostream>

// Observable pour la valeur d'enchère
class Enchere : public Observable<float> {
public:
    Enchere(std::string nomObjet, float prixInitial)
        : nomObjet(nomObjet), derniereEnchere(prixInitial) {}

    // Mettre à jour l'enchère
    void faireEnchere(float montant, const std::string& acheteur) {
        if (montant > derniereEnchere) {
            derniereEnchere = montant;
            this->acheteur = acheteur;
            notifyAll(derniereEnchere);
        }
    }

    const std::string& getAcheteur() const {
        return acheteur;
    }

    const std::string& getNomObjet() const {
        return nomObjet;
    }

    float getDerniereEnchere() const {
        return derniereEnchere;
    }

private:
    std::string nomObjet;
    float derniereEnchere;
    std::string acheteur;
};

#endif
