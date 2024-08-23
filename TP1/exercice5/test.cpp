#include <iostream>
#include "TimeStamp.hpp"

using namespace std;

int main() {
    TimeStamp t1{0, 2, -90};
    t1.print();
    t1.addSecond(3);
    t1.print();
    t1.addSecond(3);
    t1.print();
    return 0;
}