#include "Intervalle.hpp"
#include "TableauValeurs.hpp"
#include <iostream>
#include <vector>

std::vector<char> filtre(const std::vector<char>& vec, const ValeursAdmises& admises);

int main() {
    Intervalle inter('a', 'd');
    if(inter('e')) {
        std::cout << " la valeur 'e' est ok" << std::endl;
    }
    else {
        std::cout << " la valeur 'e' n'est pas ok" << std::endl;
    }
    if(inter('c')) {
        std::cout << " la valeur 'c' est ok" << std::endl;
    }
    else {
        std::cout << " la valeur 'c' n'est pas ok" << std::endl;
    }

    std::cout << "Test de la classe Intervalle terminé" << std::endl;
    

    char tab[] = {'b', 'o', 'n', 'j', 'u', 'r'};
    TableauValeurs tableau {tab, 6};

    if(tableau('j')) {
        std::cout << " la valeur 'j' est ok" << std::endl;
    }
    else {
        std::cout << " la valeur 'j' n'est pas ok" << std::endl;
    }
    if(tableau('c')) {
        std::cout << " la valeur 'c' est ok" << std::endl;
    }
    else {
        std::cout << " la valeur 'c' n'est pas ok" << std::endl;
    }

    std::cout << "Test de la classe TableauValeurs terminé" << std::endl;


    std::vector<char> res = filtre(std::vector<char>{'a', 'b', 'z', 'o'}, (ValeursAdmises&)tableau);

    for(char const& val : res) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

std::vector<char> filtre(const std::vector<char>& vec, const ValeursAdmises& admises) {
    std::vector<char> res;
    for (const char& c : vec) {
        if (admises(c)) {
            res.push_back(c);
        }
    }
    return res;
}
