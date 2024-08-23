#include "Vector.hpp"

using namespace std;

static int total_memory = 0;

Vector::Vector(): size{0}, data{nullptr} {}

Vector::Vector(int size): size{size}, data{new int[size]} {
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

Vector::~Vector() {
    delete[] data;
}

int Vector::get_size() const {
    if (data == nullptr) {
        return 0;
    }
    return size;
}

int Vector::get_at(int index) const {
    if (index < 0 || index >= size) {
        return 0;
    }
    return data[index];
}

void Vector::set_at(int index, int value) {
    if (index < 0 || index >= size) {
        return;
    }
    data[index] = value;
}

void Vector::push_back(int value) {
    int* new_data = new int[size + 1];
    for (int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    new_data[size] = value;
    delete[] data;
    data = new_data;
    size++;
}

void Vector::push_front(int value) {
    int* new_data = new int[size + 1];
    new_data[0] = value;
    for (int i = 0; i < size; i++) {
        new_data[i + 1] = data[i];
    }
    delete[] data;
    data = new_data;
    size++;
}

int Vector::pop_back() {
    if (size == 0) {
        std::cerr << "Vector is empty" << std::endl;
        return 0;
    }
    int value = data[size - 1];
    int* new_data = new int[size - 1];
    for (int i = 0; i < size - 1; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    --size;
    total_memory -= sizeof(int);
    return value;
}

int Vector::pop_front() {
    if (size == 0) {
        std::cerr << "Vector is empty" << std::endl;
        return 0;
    }
    int value = data[0];
    int* new_data = new int[size - 1];
    for (int i = 1; i < size; ++i) {
        new_data[i - 1] = data[i];
    }
    delete[] data;
    data = new_data;
    --size;
    total_memory -= sizeof(int);
    return value;
}

int Vector::get_total_memory() {
    return total_memory;
}

std::ostream& operator<<(std::ostream& os, const Vector& vector) {
    os << vector.size << " [";
    for (int i = 0; i < vector.size; i++) {
        os << vector.data[i];
        if (i < vector.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}