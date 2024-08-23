#ifndef _CONSULTANT_HPP
#define _CONSULTANT_HPP

#include "RunProjet.hpp"
#include <iostream>
#include <vector>
#include <utility>

class Consultant
{
public:
    Consultant();
    ~Consultant();

    std::pair<std::vector<int>, int> avis(const RunProjet &);
};

#endif
