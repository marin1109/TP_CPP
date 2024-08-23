#include <iostream>
#include <cstdlib>
#include "Tache.hpp"
#include "ProtoProjet.hpp"
#include "RunProjet.hpp"
#include "Gestionnaire.hpp"
#include "Consultant.hpp"
#include "Expert.hpp"

using namespace std;

int main() {
    ProtoProjet pp;
    pp.ajoute("a",10); // probablement numero 2
    cout << pp; // avec ses 3 taches
    cout << "----------" << endl;
    
    
    return EXIT_SUCCESS;
}
