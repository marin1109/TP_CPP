#include "ArticleEnSolde.hpp"

ArticleEnSolde::ArticleEnSolde(std::string nom, double prix, double tauxReduction) : Article(nom, prix), tauxReduction(tauxReduction) {}

ArticleEnSolde::ArticleEnSolde(const Article &article, double tauxReduction) : Article(article), tauxReduction(tauxReduction) {}

double ArticleEnSolde::getPrix() const {
    return Article::getPrix() * (1 - tauxReduction / 100);
}

ArticleEnSolde::~ArticleEnSolde() {
    std::cout << "Destruction de l'article en solde " << Article::getNom() << std::endl;
}

std::string ArticleEnSolde::toString() const {
    std::ostringstream oss;
    oss << Article::toString() << " (remise : " << tauxReduction << "%)";
    return oss.str();
}
