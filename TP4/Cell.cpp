#include "Cell.hpp"
#include "List.hpp"

// Constructeur privé : seul List peut instancier Cell
Cell::Cell(int val) : val(val), next(nullptr), prev(nullptr) {}

// Destructeur
Cell::~Cell() {}

// Accesseurs et mutateurs
int Cell::getVal() const {
    return val;
}

void Cell::setVal(int val) {
    this->val = val;
}

Cell* Cell::getNext() const {
    return next;
}

void Cell::setNext(Cell* next) {
    this->next = next;
}

Cell* Cell::getPrev() const {
    return prev;
}

void Cell::setPrev(Cell* prev) {
    this->prev = prev;
}

// Connexion de deux cellules
void Cell::connect(Cell* cell) {
    this->next = cell;
    if (cell != nullptr) {
        cell->prev = this;
    }
}

// Déconnexion du prochain
void Cell::disconnect_next() {
    if (this->next != nullptr) {
        this->next->prev = nullptr;
        this->next = nullptr;
    }
}

// Déconnexion du précédent
void Cell::disconnect_prev() {
    if (this->prev != nullptr) {
        this->prev->next = nullptr;
        this->prev = nullptr;
    }
}

// Affichage de la cellule
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
    os << cell.val;
    return os;
}
