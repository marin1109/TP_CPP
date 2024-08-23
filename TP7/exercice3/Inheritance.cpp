#include <iostream>

class B;

class A {
public:
    void f() {
        std::cout << "A::f()" << std::endl;
    }
    void g() {
        std::cout << "A::g()" << std::endl;
    }
    virtual void h() {
        std::cout << "A::h()" << std::endl;
    }
    void k(int i) {
        i = i;
        std::cout << "A::k(int)" << std::endl;
    }
    virtual void l(A *a) {
        a = a;
        std::cout << "A::l(A *)" << std::endl;
    }
    virtual void l(B *a) {
        a = a;
        std::cout << "A::l(B *)" << std::endl;
    }
};

class B : public A {
public:
    void f() {
        std::cout << "B::f()" << std::endl;
    }
    virtual void h() {
        std::cout << "B::g()" << std::endl;
    }
    void k(char c) {
        c = c;
        std::cout << "B::k(char)" << std::endl;
    }
    virtual void l(B *a) {
        a = a;
        std::cout << "B::l(B *)" << std::endl;
    }
};

int main() {
    A* a = new A;
    B* b = new B;
    A* ab = new B;

    std::cout << "Appels de f():" << std::endl;
    a->f(); // A::f()
    b->f(); // B::f()
    ab->f(); // A::f()

    std::cout << "Appels de g():" << std::endl;
    a->g(); // A::g()
    b->g(); // A::g()
    ab->g(); // A::g()

    std::cout << "Appels de h():" << std::endl;
    a->h(); // A::h()
    b->h(); // B::h()
    ab->h(); // B::h()

    std::cout << "Appels de k(--):" << std::endl;
    a->k('a'); // A::k(int)
    b->k(2); // B::k(char)
    ab->k(3); // A::k(int)

    std::cout << "Appels de l(--):" << std::endl;
    a->l(a); // A::l(A *)
    a->l(b); // A::l(B *)
    a->l(ab); // A::l(A *)
    // b->l(a); ne compile pas, car B::l(A *) n'existe pas
    b->l(b); // B::l(B *)
    // b->l(ab); ne compile pas car B::l(A *) n'existe pas
    ab->l(a); // A::l(A *)
    ab->l(b); // B::l(B *)
    ab->l(ab); // A::l(A *)

    return EXIT_SUCCESS;
}
