#ifndef _ARTICLE_HPP
#define _ARTICLE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Article {
private:
    const std::string nom;
    double prix;

public:
    Article(const std::string &nom, double prix);
    ~Article();

    const std::string &getNom() const;
    virtual double getPrix() const;
    virtual std::string toString() const;

    friend std::ostream &operator<<(std::ostream &os, const Article &article);
};

#endif
