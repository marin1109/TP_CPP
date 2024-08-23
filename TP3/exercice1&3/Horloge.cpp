#include "Horloge.hpp"

using namespace std;

Horloge::Horloge(): heures{0}, minutes{0}, secondes{0} {
    cout << "Horloge créée avec succès !" << endl;
}

Horloge::Horloge(int heures, int minutes, int secondes) {
    if (heures < 0 || minutes < 0 || secondes < 0) {
        throw invalid_argument("Les valeurs des heures, minutes et secondes doivent être positives.");
    }
    this->heures = (heures + (minutes / 60) + (secondes / 3600)) % 24;
    this->minutes = (minutes + (secondes / 60)) % 60;
    this->secondes = secondes % 60;
    cout << "Horloge créée avec succès !" << endl;
}

Horloge::Horloge(const Horloge& horloge): heures{horloge.heures}, minutes{horloge.minutes}, secondes{horloge.secondes} {
    cout << "Horloge copiée avec succès !" << endl;
}

Horloge& Horloge::operator=(const Horloge& horloge) {
    if (this != &horloge) {
        heures = horloge.heures;
        minutes = horloge.minutes;
        secondes = horloge.secondes;
    }
    return *this;
}

Horloge::~Horloge() {
    cout << "Destruction de l'horloge : " << *this << endl;
}

void Horloge::afficher() const {
    cout << "Il est " << heures << "h" << minutes << "m" << secondes << "s" << endl;
}

void Horloge::tick() {
    secondes++;
    if (secondes >= 60) {
        secondes = 0;
        minutes++;
        if (minutes >= 60) {
            minutes = 0;
            heures++;
            if (heures >= 24) {
                heures = 0;
                cout << "Changement de jour!" << endl;
            }
        }
    }
}

bool Horloge::estPlusPetitQue(const Horloge& autre) const {
    if (heures < autre.heures) return true;
    if (heures > autre.heures) return false;
    if (minutes < autre.minutes) return true;
    if (minutes > autre.minutes) return false;
    return secondes < autre.secondes;
}

std::ostream& operator<<(std::ostream& os, const Horloge& horloge) {
    os << (horloge.heures < 10 ? "0" : "") << horloge.heures << "H "
       << (horloge.minutes < 10 ? "0" : "") << horloge.minutes << "M "
       << (horloge.secondes < 10 ? "0" : "") << horloge.secondes << "S";
    return os;
}
