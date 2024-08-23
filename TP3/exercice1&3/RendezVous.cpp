#include "RendezVous.hpp"

RendezVous::RendezVous(const Date& date, const Horloge& heure) : date{date}, heure{heure} {
    std::cout << "Rendez-vous créé avec succès !" << std::endl;
}

RendezVous::~RendezVous() {
    std::cout << "Destruction du rendez-vous : " << *this << std::endl;
}

Date RendezVous::getDate() const {
    return date;
}

Horloge RendezVous::getHeure() const {
    return heure;
}

void RendezVous::setDate(const Date& date) {
    this->date = date;
}

void RendezVous::setHeure(const Horloge& heure) {
    this->heure = heure;
}

std::ostream& operator<<(std::ostream& os, const RendezVous& rdv) {
    os << "Rendez-vous le " << rdv.date << " à " << rdv.heure;
    return os;
}
