#ifndef _PROTO_PROJET_HPP
#define _PROTO_PROJET_HPP

#include <iostream>
#include "Tache.hpp"
#include <vector>
#include <random>
#include <utility>
#include <memory>

class ProtoProjet {
    private:
        std::vector<std::unique_ptr<Tache>> taches;
        
    public:
        ProtoProjet();
        virtual ~ProtoProjet();

        bool ajoute(const std::string& nom, int duree);
        bool ajoute(const std::string& nom, int duree, int idTache);
        bool ajoute(const std::string& nom, int duree, int Tache1, int Tache2);

        const std::vector<std::unique_ptr<Tache>>& getTaches() const;

        void cleanMarks();

        void topologicalSort();

        friend std::ostream& operator<<(std::ostream& os, const ProtoProjet& protoProjet);
};

#endif
