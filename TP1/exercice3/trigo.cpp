#include <cmath>
#include <iostream>
#include "trigo.hpp"

using namespace std;

double sinus(double const d, char const c) {
    switch (c) {
        case 'r':
            return sin(d);
        case 'd':
            return sin(d * M_PI / 180);
        case 'g':
            return sin(d * M_PI / 200);
        default:
            throw invalid_argument("Unité inconnue");
    }
}