#include "Article.hpp"

Article::Article(const std::string &nom, double prix) : nom(nom), prix(prix) {}

Article::~Article() {
    std::cout << "Destruction de l'article " << nom << std::endl;
}

const std::string &Article::getNom() const {
    return nom;
}

double Article::getPrix() const {
    return prix;
}

std::string Article::toString() const {
    return nom + " : " + std::to_string(getPrix()) + "€";
}

std::ostream &operator<<(std::ostream &os, const Article &article) {
    os << article.toString();
    return os;
}
