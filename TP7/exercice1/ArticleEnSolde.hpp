#ifndef _ARTICLEENSOLDE_HPP
#define _ARTICLEENSOLDE_HPP

#include "Article.hpp"

class ArticleEnSolde : public Article {
private:
    double tauxReduction;

public:
        ArticleEnSolde(std::string nom, double prix, double tauxReduction = 10.0);
        ArticleEnSolde(const Article &article, double tauxReduction = 10.0);
        ArticleEnSolde(const ArticleEnSolde &articleEnSolde) = delete;

        ~ArticleEnSolde();

        double getPrix() const;

        std::string toString() const;
        
};    

#endif
