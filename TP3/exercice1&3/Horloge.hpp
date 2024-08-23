#ifndef HORLOGE_HPP
#define HORLOGE_HPP

#include <iostream>

class Horloge {
private:
    int heures;
    int minutes;
    int secondes;

public:
    Horloge();
    Horloge(int heures, int minutes, int secondes);
    Horloge(const Horloge& horloge);
    Horloge& operator=(const Horloge& horloge); // Déclaration de l'opérateur d'affectation
    ~Horloge();

    void afficher() const;
    void tick();

    bool estPlusPetitQue(const Horloge& autre) const;

    friend std::ostream& operator<<(std::ostream& os, const Horloge& horloge);
};

#endif // HORLOGE_HPP
