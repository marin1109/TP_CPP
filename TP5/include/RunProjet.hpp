#ifndef _RUN_PROJET_HPP
#define _RUN_PROJET_HPP

#include "ProtoProjet.hpp"
#include "Tache.hpp"
#include <iostream>
#include <vector>
#include <memory>

class RunProjet : public ProtoProjet {
    private:
        std::vector<std::unique_ptr<Tache>> taches;
        
    public:
        RunProjet(ProtoProjet& protoProjet);
        virtual ~RunProjet() = default;

        const std::vector<std::unique_ptr<Tache>>& getTaches() const;

        void run(int idTache);
        void run(const std::vector<int>& idTaches);

        friend std::ostream& operator<<(std::ostream& os, const RunProjet& runProjet);
};

#endif
