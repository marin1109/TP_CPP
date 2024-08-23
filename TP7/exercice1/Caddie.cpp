#include "Caddie.hpp"

void Caddie::ajoute(const std::shared_ptr<Article> &article) {
    articles.push_back(article);
}

std::ostream &operator<<(std::ostream &os, const Caddie &caddie) {
    for (const auto &article : caddie.articles) {
        os << *article << std::endl;
    }
    return os;
}
