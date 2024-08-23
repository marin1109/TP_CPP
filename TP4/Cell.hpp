#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>

class List; // Déclaration avant la définition de la classe

class Cell {
private:
    int val;
    Cell* next;
    Cell* prev;

    // La classe List est amie et peut accéder aux membres privés de Cell
    friend class List;

    // Constructeur privé pour que seules les classes amies puissent instancier Cell
    Cell(int val);

public:
    // Le constructeur public est supprimé ; Cell ne peut être instanciée que par List
    // Cell() = delete; // Si vous utilisez C++11 ou supérieur pour désactiver le constructeur par défaut

    // Destructeur public
    virtual ~Cell();

    // Méthodes d'accès pour que List puisse manipuler les cellules
    int getVal() const;
    void setVal(int val);
    Cell* getNext() const;
    void setNext(Cell* next);
    Cell* getPrev() const;
    void setPrev(Cell* prev);

    // Méthodes pour connecter et déconnecter les cellules
    void connect(Cell* cell);
    void disconnect_next();
    void disconnect_prev();

    // Méthode pour afficher la cellule
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};

#endif // CELL_HPP
