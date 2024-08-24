#include "Vecteur.hpp"
#include <iostream>

int main() {
    Vecteur v1(3, 4);
    Vecteur v2(1, 2);

    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    // Test des opérateurs == et !=
    if (v1 == v2) {
        std::cout << "Les vecteurs sont égaux." << std::endl;
    } else {
        std::cout << "Les vecteurs sont différents." << std::endl;
    }

    // Test des opérateurs +, -, *
    std::cout << "v1 + v2 = " << v1 + v2 << std::endl;

    std::cout << "v1 - v2 = " << v1 - v2 << std::endl;

    double produit_scalaire = v1 * v2;
    std::cout << "v1 * v2 (produit scalaire) = " << produit_scalaire << std::endl;

    // Test de l'accès aux coordonnées avec l'opérateur []
    Vecteur v;
    v[0] = 9;
    v[1] = v[0];
    std::cout << "v = " << v << std::endl;

    // Test de la méthode norm()
    std::cout << "Norme de v1: " << v1.norm() << std::endl;

    return EXIT_SUCCESS;
}
