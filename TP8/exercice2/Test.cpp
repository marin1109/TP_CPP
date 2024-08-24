#include <iostream>

#include "include/Figure.hpp"
#include "include/Triangle.hpp"
#include "include/Quadrilatere.hpp"
#include "include/Losange.hpp"
#include "include/Rectangle.hpp"
#include "include/Carre.hpp"

int main() {
    Triangle t("Triangle", Vecteur(0, 0), Vecteur(0, 1), Vecteur(1, 0));
    t.test();
    std::cout << t << std::endl;
    t.perimeter();
    std::cout << "Area: " << t.area() << std::endl << std::endl;


    Quadrilatere q("Quadrilatere", Vecteur(0, 0), Vecteur(0, 1), Vecteur(1, 1), Vecteur(1, 0));
    q.test();
    std::cout << q << std::endl;
    q.perimeter();
    std::cout << "Area: " << q.area() << std::endl << std::endl;


    Rectangle r("Rectangle", Vecteur(0, 0), Vecteur(0, 2), Vecteur(1, 2), Vecteur(1, 0));
    r.test();
    std::cout << r << std::endl;
    r.perimeter();
    std::cout << "Area: " << r.area() << std::endl << std::endl;


    Losange l("Losange", Vecteur(0, 0), Vecteur(0, 1), Vecteur(1, 2), Vecteur(1, 1));
    l.test();
    std::cout << l << std::endl;
    l.perimeter();
    std::cout << "Area: " << l.area() << std::endl << std::endl;


    Carre c("Carre", Vecteur(0, 0), Vecteur(0, 1), Vecteur(1, 1), Vecteur(1, 0));
    c.test();
    std::cout << c << std::endl;
    c.perimeter();
    std::cout << "Area: " << c.area() << std::endl;
    
    return EXIT_SUCCESS;
}
