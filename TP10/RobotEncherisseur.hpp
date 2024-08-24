#ifndef _ROBOTENCHERISSEUR_HPP
#define _ROBOTENCHERISSEUR_HPP

#include <iostream>
#include <memory>
#include <string>
#include "Enchere.hpp"

class RobotEncherisseur : public Observateur<float>, public std::enable_shared_from_this<RobotEncherisseur> {
public:
    RobotEncherisseur(std::string nomAcheteur, Enchere& enchere, float maxMontant)
        : nomAcheteur(nomAcheteur), enchere(enchere), maxMontant(maxMontant) {
        enchere.addObserver(shared_from_this());
    }

    ~RobotEncherisseur() {
        enchere.removeObserver(shared_from_this());
    }

    void update(const float& nouvelleEnchere) override {
        if (nouvelleEnchere < maxMontant && enchere.getAcheteur() != nomAcheteur) {
            float newBid = nouvelleEnchere + 1.0f;  // Enchérir de 1 unité
            enchere.faireEnchere(newBid, nomAcheteur);
            std::cout << nomAcheteur << " a surenchéri à " << newBid << " pour l'objet " << enchere.getNomObjet() << std::endl;
        }
    }

private:
    std::string nomAcheteur;
    Enchere& enchere;
    float maxMontant;
};

#endif
