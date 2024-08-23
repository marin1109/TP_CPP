#include <iostream>

using namespace std;

class A {
public:
    virtual void f() {
        cout << "A::f()" << endl;
    }
    virtual void g() {
        cout << "A::g()" << endl;
    }
};

class B : public A {
public:
    void f() override {
        cout << "B::f()" << endl;
    }
};

class C : public B {
public:
    void g() override {
        cout << "B::g()" << endl;
    }
};

class D : public B {
public:
    void f() override {
        cout << "D::f()" << endl;
    }
    void g() override {
        cout << "D::g()" << endl;
    }
};

class E : public C {
public:
    void g() override {
        cout << "E::g()" << endl;
    }
};

int main() {
    cout << "---- 1 ----" << endl;
    A *a = new A();
    a->f();
    a->g();

    cout << "---- 2 ----" << endl;
    A *b = new B();
    b->f();
    b->g();

    cout << "---- 3 ----" << endl;
    B *c = new C();
    c->f();
    c->g();

    cout << "---- 4 ----" << endl;
    B *d = new D();
    d->f();
    d->g();

    cout << "---- 5 ----" << endl;
    A *e = new E();
    e->f();
    static_cast<B*>(e)->g();

    return 0;
}
