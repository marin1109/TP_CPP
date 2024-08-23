#include "triangle.hpp"
#include "trigo.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double autreCote(double const angle, char const v, double const l) {
    double AB = l * sinus(angle, v);
    return sqrt(pow(l, 2) - pow(AB, 2));
}