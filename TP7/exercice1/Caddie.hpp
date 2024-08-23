#ifndef _CADDIE_HPP
#define _CADDIE_HPP

#include "Article.hpp"
#include "ArticleEnSolde.hpp"
#include <vector>
#include <memory>

class Caddie {
private:
    std::vector<std::shared_ptr<Article>> articles;
    int taille;

public:
    Caddie() = default;
    ~Caddie() = default;

    void ajoute(const std::shared_ptr<Article> &article);

    friend std::ostream &operator<<(std::ostream &os, const Caddie &caddie);
};

#endif
