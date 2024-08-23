#include <iostream>
#include "List.hpp"

int main() {
    // Création d'une liste
    List list1;
    list1.insert(0, 10);
    list1.insert(1, 20);
    list1.insert(2, 30);

    // Utilisation du constructeur de copie
    List list2 = list1;

    std::cout << "Liste 1 : " << list1 << std::endl;
    std::cout << "Liste 2 (copie) : " << list2 << std::endl;

    // Modification de list1
    list1.set(1, 25);
    std::cout << "Liste 1 après modification : " << list1 << std::endl;
    std::cout << "Liste 2 après modification de list1 : " << list2 << std::endl;

    // Utilisation de l'opérateur d'affectation
    List list3;
    list3.insert(0, 100);
    list3 = list1;

    std::cout << "Liste 3 après affectation de list1 : " << list3 << std::endl;
    std::cout << "Liste 1 après affectation à list3 : " << list1 << std::endl;

    return 0;
}
