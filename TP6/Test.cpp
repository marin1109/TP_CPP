#include "Scrutin.hpp"
#include "Urne.hpp"
#include "ChoixVote.hpp"
#include <iostream>

int main() {
    // Création d'un scrutin avec 3 bureaux de vote et 3 options (Oui, Non, VoteBlanc)
    Scrutin scrutin(3, 3);

    // Voter dans le premier bureau de vote (ID = 0)
    Urne& urne1 = scrutin.getUrne(0);
    urne1.voter(ChoixVote::Oui);
    urne1.voter(ChoixVote::Non);
    urne1.voter(ChoixVote::VoteBlanc);

    // Voter dans le deuxième bureau de vote (ID = 1)
    Urne& urne2 = scrutin.getUrne(1);
    urne2.voter(ChoixVote::Oui);
    urne2.voter(ChoixVote::Oui);
    urne2.voter(ChoixVote::Non);

    // Afficher les résultats partiels des urnes
    std::cout << "Résultats du bureau de vote 1 (ID = 0):" << std::endl;
    urne1.afficherResultats();

    std::cout << "Résultats du bureau de vote 2 (ID = 1):" << std::endl;
    urne2.afficherResultats();

    // Terminer le scrutin
    scrutin.terminerScrutin();

    // Tenter de voter après la fin du scrutin (ce qui devrait échouer)
    if (!urne1.voter(ChoixVote::Oui)) {
        std::cout << "Impossible de voter après la fin du scrutin." << std::endl;
    }

    // Afficher les résultats complets du scrutin
    std::cout << "Résultats complets du scrutin:" << std::endl;
    scrutin.afficherResultatsComplet();

    return 0;
}
