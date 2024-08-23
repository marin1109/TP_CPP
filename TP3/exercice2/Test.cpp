#include "BoxInt.hpp"
#include <memory>

using namespace std;

// void fonction1(BoxInt t) { t.setValue (345); }
// void fonction2(BoxInt *t) { t->setValue (678); }
// void fonction3(BoxInt &t) { t.setValue (1); }
// void fonction4(const BoxInt &t) { t.setValue (13); }
// void fonction5(const BoxInt *t) { t -> setValue (13); }
// void fonction6(BoxInt * const t) { t -> setValue (13); }
// void fonction7(BoxInt const * const t) { t -> setValue (13); }
// void fonction8(const BoxInt &t) { cout << t.getValue() << endl; }

void un_test() {
    BoxInt un_int {42};
    BoxInt un_autre_int {un_int};
    std::unique_ptr<BoxInt> n = std::make_unique<BoxInt>(54);  // Utilisation d'un pointeur intelligent
    // Le pointeur intelligent détruira automatiquement l'instance lorsqu'il sortira de la portée
}

int main() {
    // BoxInt monTest {42};
    // cout << monTest << endl << endl;

    // monTest.setValue(0);
    // cout << monTest << endl << endl;
    
    // fonction1(monTest);
    // cout << monTest << endl << endl;
    
    // fonction2 (& monTest);
    // cout << monTest << endl << endl;
    
    // fonction3(monTest);
    // cout << monTest << endl << endl;

    un_test();
    
    return EXIT_SUCCESS;

}