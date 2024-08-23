#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>

class Date {
private:
    int jour;
    int mois;
    int annee;

public:
    Date();
    Date(int jour, int mois, int annee);
    Date(const Date& date);
    Date& operator=(const Date& date); // Déclaration de l'opérateur d'affectation
    ~Date();

    std::string affiche_aux(int mois) const;
    void afficher() const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif // DATE_HPP
