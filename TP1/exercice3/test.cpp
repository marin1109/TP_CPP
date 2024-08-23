#include <iostream>
#include "triangle.hpp"

using namespace std;

int main() {
    int angle;
    int longueur;
    cout << "Entrez un angle : ";
    cin >> angle;
    cout << "Entrez une longueur : ";
    cin >> longueur;
    cout << autreCote(angle, 'd', longueur) << endl;

    return 0;
}