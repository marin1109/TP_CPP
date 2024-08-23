#ifndef _PROJET_HPP
#define _PROJET_HPP

#include "Tache.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>

class Projet {
    protected:
        std::vector<Tache*> taches;
        std::string nom;

    public:
        Projet(std::string nom);
        virtual ~Projet();

        virtual std::pair<int, int> pick_two_random_tasks();
        virtual Tache* contains(int idTache) const;
        virtual Tache* contains(const std::string nomTache) const;
        virtual const std::vector<Tache*>& getTaches() const;
        virtual void topologicalSort();
};

#endif
