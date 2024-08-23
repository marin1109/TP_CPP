#ifndef _GESTIONNAIRE_HPP
#define _GESTIONNAIRE_HPP

#include "RunProjet.hpp"
#include <iostream>
#include <vector>
#include <utility>

class Gestionnaire {
    public:
        virtual std::pair<std::vector<int>, int> avis(const RunProjet &) = 0;
};

#endif
