#pragma once
#include <vector>
#include "../../../Particule/Particule.h"
#include <map>
#include "../Triplet/Triplet.h"


class Grille {
    private:
        std::map<Triplet, std::vector<Particule*>> grille;
        double taille_case;
    public:
        Grille() = delete;
        Grille(std::vector<Particule*> particules): taille_case(2*particules[0]->getSigma()) {for (Particule* p : particules) ajouterParticule(p);} //done
        void ajouterParticule(Particule* particule); // done
        void retirerParticule(Particule* particule); //done
        void mettreAJour(Particule* particule) {retirerParticule(particule); ajouterParticule(particule);} // done
        std::vector<Particule*> getVoisins(const Particule* particule) const; // done
};
