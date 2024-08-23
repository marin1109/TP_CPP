#include "Date.hpp"
#include "Horloge.hpp"
#include "RendezVous.hpp"

Horloge& trouverPlusPetiteHorloge(Horloge* horloges, int taille) {
    if (taille <= 0) {
        throw std::invalid_argument("La taille du tableau doit être positive.");
    }

    Horloge* plusPetite = &horloges[0];
    for (int i = 1; i < taille; ++i) {
        if (horloges[i].estPlusPetitQue(*plusPetite)) {
            plusPetite = &horloges[i];
        }
    }
    return *plusPetite;
}

int main() {
    Horloge horloges[] = {
        Horloge(14, 30, 0),
        Horloge(9, 45, 15),
        Horloge(23, 59, 59),
        Horloge(6, 0, 0)
    };

    int taille = sizeof(horloges) / sizeof(Horloge);

    try {
        Horloge& plusPetiteHorloge = trouverPlusPetiteHorloge(horloges, taille);
        std::cout << "La plus petite horloge est : " << plusPetiteHorloge << std::endl;

        // Avancer la plus petite horloge
        plusPetiteHorloge.tick();
        std::cout << "Après tick, la plus petite horloge est : " << plusPetiteHorloge << std::endl;

        // Vérifier que le changement est également visible dans le tableau
        std::cout << "Vérification dans le tableau : " << horloges[1] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
