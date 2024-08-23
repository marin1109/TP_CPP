#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Cell.hpp"

class List {
private:
    Cell* head;
    Cell* tail;

    void copyList(const List& list);

public:
    List();
    virtual ~List();

    int length();
    int get(int index);
    int find(int value);
    void set(int index, int value);
    void insert(int index, int value);
    void remove(int index);

    List& operator=(const List& list);

    friend std::ostream& operator<<(std::ostream& os, const List& list);
};

#endif // LIST_HPP
