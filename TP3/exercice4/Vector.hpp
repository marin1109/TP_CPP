#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class Vector {
    private:
        int size;
        int* data;
        static int total_memory;

    public:
        Vector();
        Vector(int size);
        ~Vector();

        Vector(const Vector&) = delete;
        Vector& operator=(const Vector&) = delete;

        int get_size() const;
        int get_at(int index) const;
        void set_at(int index, int value);
        void push_back(int value);
        void push_front(int value);
        int pop_back();
        int pop_front();

        static int get_total_memory();

        friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
};

#endif // VECTOR_HPP
