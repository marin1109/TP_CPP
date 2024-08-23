#include "List.hpp"

using namespace std;

List::List() : head(nullptr), tail(nullptr) {}

List::~List() {
    while (head != nullptr) {
        Cell* next = head->getNext();
        delete head;
        head = next;
    }
}

int List::length() {
    int length = 0;
    Cell* current = head;
    while (current != nullptr) {
        length++;
        current = current->getNext();
    }
    return length;
}

int List::get(int index) {
    if (index < 0 || index >= length()) {
        throw out_of_range("Index out of range");
    }
    Cell* current = head;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return current->getVal();
}

int List::find(int value) {
    int index = 0;
    Cell* current = head;
    while (current != nullptr) {
        if (current->getVal() == value) {
            return index;
        }
        current = current->getNext();
        index++;
    }
    return -1;
}

void List::set(int index, int value) {
    if (index < 0 || index >= length()) {
        throw out_of_range("Index out of range");
    }
    Cell* current = head;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    current->setVal(value);
}

void List::insert(int index, int value) {
    if (index < 0 || index > length()) {
        throw out_of_range("Index out of range");
    }
    Cell* newCell = new Cell(value);
    
    if (index == 0) {
        // Insertion au début
        newCell->setNext(head);
        if (head != nullptr) {
            head->setPrev(newCell);
        }
        head = newCell;
        if (tail == nullptr) {
            tail = newCell;
        }
    } else {
        Cell* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->getNext();
        }
        newCell->setNext(current->getNext());
        if (current->getNext() != nullptr) {
            current->getNext()->setPrev(newCell);
        }
        current->setNext(newCell);
        newCell->setPrev(current);
        if (newCell->getNext() == nullptr) {
            tail = newCell;
        }
    }
}

void List::remove(int index) {
    if (index < 0 || index >= length()) {
        throw out_of_range("Index out of range");
    }
    
    if (index == 0) {
        // Suppression de la première cellule
        Cell* next = head->getNext();
        delete head;
        head = next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->setPrev(nullptr);
        }
    } else {
        Cell* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->getNext();
        }
        Cell* next = current->getNext()->getNext();
        delete current->getNext();
        current->setNext(next);
        if (next == nullptr) {
            tail = current;
        } else {
            next->setPrev(current);
        }
    }
}

// Méthode pour copier la liste
void List::copyList(const List& other) {
    if (other.head == nullptr) {
        head = tail = nullptr;
        return;
    }

    Cell* currentOther = other.head;
    while (currentOther != nullptr) {
        insert(length(), currentOther->getVal());
        currentOther = currentOther->getNext();
    }
}

// Opérateur d'affectation
List& List::operator=(const List& other) {
    if (this == &other) {
        return *this; // Auto-assignment check
    }

    // Nettoyage de l'ancienne liste
    while (head != nullptr) {
        Cell* next = head->getNext();
        delete head;
        head = next;
    }

    // Copie de la nouvelle liste
    copyList(other);

    return *this;
}

ostream& operator<<(ostream& os, const List& list) {
    Cell* current = list.head;
    os << "[";
    while (current != nullptr) {
        os << *current;
        current = current->getNext();
        if (current != nullptr) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
