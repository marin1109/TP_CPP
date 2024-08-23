#ifndef _TACHE
#define _TACHE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Tache {
    private:
        std::string nom_;
        static int nbTaches_;
        int idTache_;
        bool terminee_ = false;
        int duree_;
        std::vector<Tache*> dependances_;

    public:
        bool mark_ = false;

        Tache(std::string nom, int duree);
        virtual ~Tache();

        bool realise();
        bool depends_from(const Tache& tache);
        bool ajouteDependance(Tache& tache);
        int dureeParal();
        
        int getIdTache() const;
        std::string getNom() const;
        int getDuree() const;
        bool getTerminee() const;

        void setTerminee(bool terminee);
        void setDuree(int duree);
        void setNom(const std::string& nom);

        static int getNbTaches();

        void run(int idTache);

        void PP_postfixe(std::vector<Tache*>& taches);

        friend std::ostream& operator<<(std::ostream& os, const Tache& tache);
        friend bool operator==(const Tache& tache1, const Tache& tache2);
        const Tache& operator=(const Tache& tache);
};

#endif
