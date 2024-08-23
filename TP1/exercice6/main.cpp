#include <iostream>
#include <vector>

int plus(int a, int b) {
    return a + b;
}

double plus(double a, double b) {
    return a + b;
}

int somme(std::vector<int> tab) {
    int sum = 0;
    for (size_t i = 0; i < tab.size(); i++) {
        sum += tab[i];
    }
    return sum;
}

double somme(std::vector<double> tab) {
    double sum = 0.0;
    for (size_t i = 0; i < tab.size(); i++) {
        sum += tab[i];
    }
    return sum;
}

int sommeTab(int tab[], int taille) {
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tab[i];
    }
    return somme;
}

double sommeTab(double tab[], int taille) {
    double somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tab[i];
    }
    return somme;
}

int main() {
    std::cout << plus(1, 2) << std::endl;
    std::cout << plus(1.1, 2.2) << std::endl;

    std::vector<int> tab = {1, 2, 3, 4, 5};
    std::cout << somme(tab) << std::endl;
    std::vector<double> tab2 = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << somme(tab2) << std::endl;

    int tab3[] = {1, 2, 3, 4, 5};
    std::cout << sommeTab(tab3, 5) << std::endl;
    double tab4[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << sommeTab(tab4, 5) << std::endl;

    return 0;
}