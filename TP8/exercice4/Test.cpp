#include "Fraction.hpp"

int main() {
    Fraction f1(1, 2);
    Fraction f2(1, 3);

    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;

    Fraction f3 = f1 + f2;
    std::cout << "f1 + f2 = " << f3 << std::endl;

    Fraction f4 = f1 - f2;
    std::cout << "f1 - f2 = " << f4 << std::endl;

    Fraction f5 = f1 + 1;
    std::cout << "f1 + 1 = " << f5 << std::endl;

    Fraction f6 = 1 + f2;
    std::cout << "1 + f2 = " << f6 << std::endl;

    return EXIT_SUCCESS;
}
