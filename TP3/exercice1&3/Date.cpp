#include "Date.hpp"

using namespace std;

Date::Date(): jour{1}, mois{1}, annee{1970} {
    cout << "Date créée avec succès !" << endl;
}

Date::Date(int jour, int mois, int annee): jour{jour}, mois{mois}, annee{annee} {
    if (jour < 1 || jour > 30 || mois < 1 || mois > 12 || annee < 1970) {
        this->jour = 1;
        this->mois = 1;
        this->annee = 1970;
    }
    cout << "Date créée avec succès !" << endl;
}

Date::Date(const Date& date): jour{date.jour}, mois{date.mois}, annee{date.annee} {
    cout << "Date copiée avec succès !" << endl;
}

Date& Date::operator=(const Date& date) {
    if (this != &date) {
        jour = date.jour;
        mois = date.mois;
        annee = date.annee;
    }
    return *this;
}

Date::~Date() {
    cout << "Destruction de la date : " << *this << endl;
}

string Date::affiche_aux(int mois) const {
    switch (mois) {
        case 1: return "Janvier";
        case 2: return "Février";
        case 3: return "Mars";
        case 4: return "Avril";
        case 5: return "Mai";
        case 6: return "Juin";
        case 7: return "Juillet";
        case 8: return "Août";
        case 9: return "Septembre";
        case 10: return "Octobre";
        case 11: return "Novembre";
        case 12: return "Décembre";
        default: return "Mois invalide";
    }
}

void Date::afficher() const {
    cout << (jour < 10 ? "0" : "") << jour << " " << affiche_aux(mois) << " " << annee << endl;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << (date.jour < 10 ? "0" : "") << date.jour << "/" << (date.mois < 10 ? "0" : "") << date.mois << "/" << date.annee;
    return os;
}
