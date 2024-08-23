#ifndef RENDEZVOUS_HPP
#define RENDEZVOUS_HPP

#include "Date.hpp"
#include "Horloge.hpp"

#include <iostream>

class RendezVous {
private:
    Date date;
    Horloge heure;

public:
    RendezVous(const Date& date, const Horloge& heure);
    ~RendezVous();

    Date getDate() const;
    Horloge getHeure() const;

    void setDate(const Date& date);
    void setHeure(const Horloge& heure);

    friend std::ostream& operator<<(std::ostream& os, const RendezVous& rdv);
};

#endif // RENDEZVOUS_HPP
