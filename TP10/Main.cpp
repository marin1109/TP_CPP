#include "Observateur.hpp"
#include "Observable.hpp"
#include "Enchere.hpp"
#include "RobotEncherisseur.hpp"
#include <map>
#include <memory>

int main() {
    std::map<std::string, std::shared_ptr<Enchere>> objetsEnVente;
    std::map<std::string, std::shared_ptr<RobotEncherisseur>> robots;

    while (true) {
        std::string commande;
        std::cout << "Entrez une commande: ";
        std::cin >> commande;

        if (commande == "vendre") {
            std::string nomObjet;
            float prixInitial;
            std::cout << "Nom de l'objet: ";
            std::cin >> nomObjet;
            std::cout << "Prix initial: ";
            std::cin >> prixInitial;
            objetsEnVente[nomObjet] = std::make_shared<Enchere>(nomObjet, prixInitial);
        } else if (commande == "encherir") {
            std::string nomAcheteur, nomObjet;
            float montant;
            std::cout << "Nom de l'acheteur: ";
            std::cin >> nomAcheteur;
            std::cout << "Nom de l'objet: ";
            std::cin >> nomObjet;
            std::cout << "Montant de l'enchère: ";
            std::cin >> montant;
            if (objetsEnVente.count(nomObjet)) {
                objetsEnVente[nomObjet]->faireEnchere(montant, nomAcheteur);
            } else {
                std::cout << "Objet non trouvé." << std::endl;
            }
        } else if (commande == "auto_encherir") {
            std::string nomAcheteur, nomObjet;
            float montantMax;
            std::cout << "Nom de l'acheteur: ";
            std::cin >> nomAcheteur;
            std::cout << "Nom de l'objet: ";
            std::cin >> nomObjet;
            std::cout << "Montant maximal: ";
            std::cin >> montantMax;
            if (objetsEnVente.count(nomObjet)) {
                robots[nomAcheteur] = std::make_shared<RobotEncherisseur>(nomAcheteur, *objetsEnVente[nomObjet], montantMax);
            } else {
                std::cout << "Objet non trouvé." << std::endl;
            }
        } else if (commande == "annuler_auto_encherir") {
            std::string nomAcheteur;
            std::cout << "Nom de l'acheteur: ";
            std::cin >> nomAcheteur;
            robots.erase(nomAcheteur);
        } else if (commande == "fin") {
            std::string nomObjet;
            std::cout << "Nom de l'objet: ";
            std::cin >> nomObjet;
            if (objetsEnVente.count(nomObjet)) {
                std::cout << "Enchère terminée. Vainqueur: " << objetsEnVente[nomObjet]->getAcheteur()
                          << " avec " << objetsEnVente[nomObjet]->getDerniereEnchere() << " unités." << std::endl;
                objetsEnVente.erase(nomObjet);
            } else {
                std::cout << "Objet non trouvé." << std::endl;
            }
        } else if (commande == "quit") {
            break;
        } else {
            std::cout << "Commande inconnue." << std::endl;
        }
    }

    return 0;
}
