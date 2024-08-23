#ifndef _EXPERT_HPP
#define _EXPERT_HPP

#include "Gestionnaire.hpp"
#include <iostream>
#include <vector>
#include <utility>

class Expert : public Gestionnaire {
public:
    Expert();
    ~Expert();

    std::pair<std::vector<int>, int> avis(const RunProjet &);
};

#endif
