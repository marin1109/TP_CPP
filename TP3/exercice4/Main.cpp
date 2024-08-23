#include "Vector.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

void test_vector() {
    Vector myVector;
    std::vector<int> stdVector;

    srand(time(0));

    // Test push_back
    for (int i = 0; i < 10; ++i) {
        int val = rand() % 100;
        myVector.push_back(val);
        stdVector.push_back(val);
    }

    std::cout << "After push_back operations:\n";
    std::cout << "My Vector: " << myVector << "\n";
    std::cout << "STD Vector: [";
    for (int i : stdVector) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    // Test push_front
    for (int i = 0; i < 5; ++i) {
        int val = rand() % 100;
        myVector.push_front(val);
        stdVector.insert(stdVector.begin(), val);
    }

    std::cout << "After push_front operations:\n";
    std::cout << "My Vector: " << myVector << "\n";
    std::cout << "STD Vector: [";
    for (int i : stdVector) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    // Test pop_back
    for (int i = 0; i < 3; ++i) {
        myVector.pop_back();
        stdVector.pop_back();
    }

    std::cout << "After pop_back operations:\n";
    std::cout << "My Vector: " << myVector << "\n";
    std::cout << "STD Vector: [";
    for (int i : stdVector) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    // Test pop_front
    for (int i = 0; i < 3; ++i) {
        myVector.pop_front();
        stdVector.erase(stdVector.begin());
    }

    std::cout << "After pop_front operations:\n";
    std::cout << "My Vector: " << myVector << "\n";
    std::cout << "STD Vector: [";
    for (int i : stdVector) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";
}

int main() {
    test_vector();
    return 0;
}
