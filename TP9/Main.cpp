#include <iostream>
#include "MonPtrU.hpp"

using namespace std;

class A {
public:
    int v;
    A(int x) : v(x) {}
};

template <class T>
void f(Mon_ptr_u<T> x) {}

template <class T>
void g(Mon_ptr_u<T>& x) {}

int main() {
    // Tests 1
    cout << "Test 1:" << endl;
    Mon_ptr_u<A> p1{ new A{1} };


    // Tests 2
    cout << "Test 2:" << endl;
    // Mon_ptr_u<A> p1bis{ p1 };                        // Ne doit pas marcher
    // f(p1);                                           // Ne doit pas marcher
    g(p1);                                              // Est OK
    Mon_ptr_u<A> p1bis{ nullptr };
    // p1bis = p1;                                      // Ne doit pas marcher


    // Tests 3
    cout << "----------" << endl;
    cout << "Test 3:" << endl;
    cout << (p1.release())->v << endl;
    // cout << (p1.release())->v << endl;               // ne marche plus
    cout << p1.release() << endl;                       // affiche le 0 correspondant à nullptr


    // Tests 4
    cout << "----------" << endl;
    cout << "Test 4:" << endl;
    Mon_ptr_u<A> p2{ new A{2} };
    p1 = p2;
    // cout << (p2.release())->v << endl;               // ne doit pas marcher
    cout << p2.release() << endl;                       // affiche le 0 correspondant à nullptr
    cout << (p1.release())->v << endl;                  // affiche 2
    cout << p1.release() << endl;                       // affiche le 0 correspondant à nullptr
    Mon_ptr_u<A> p3{ new A{3} };
    p3 = p3;
    p3 = p3;
    cout << (p3.release())->v << endl;                  // affiche 3
    cout << p3.release() << endl;                       // affiche le 0 correspondant à nullptr
    p3 = p3;
    cout << p3.release() << endl;                       // affiche le 0 correspondant à nullptr
    p3 = p3;


    // Tests 5
    cout << "----------" << endl;
    cout << "Test 5:" << endl;
    Mon_ptr_u<A> p4{ new A{4} }, p5{ new A{5} };
    p4.echange(p5);
    cout << (p4.release())->v << endl;                  // affiche 5
    cout << (p5.release())->v << endl;                  // affiche 4


    // Tests 6
    cout << "----------" << endl;
    cout << "Test 6:" << endl;
    Mon_ptr_u<A> p6{ new A{6} };
    if (p6) 
        cout << "p6 pointe vers la valeur " << (p6.release())->v << endl;
    else 
        cout << "p6 pointe vers nullptr" << endl;

    if (p6) 
        cout << "p6 pointe vers la valeur " << (p6.release())->v << endl;
    else 
        cout << "p6 pointe vers nullptr" << endl;


    // Tests 7
    cout << "----------" << endl;
    cout << "Test 7:" << endl;
    Mon_ptr_u<A> p7{ new A{7} };
    cout << "p7 contient " << p7->v << endl;
    cout << "p7 contient " << (*p7).v << endl;


    // Tests 8
    cout << "----------" << endl;
    cout << "Test 8:" << endl;
    A* a = new A{7};
    Mon_ptr_u<A> p8{ a };
    // Mon_ptr_u<A> p9{ a };                            // Doit lever une exception
    Mon_ptr_u<A> p9{ new A{4} };
    p9 = p8;
    p9.release();
    // Mon_ptr_u<A> p10{ a };                           // Doit lever une exception

    return EXIT_SUCCESS;
}
