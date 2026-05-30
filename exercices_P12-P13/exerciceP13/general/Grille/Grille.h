#pragma once
#include <vector>
#include "../../../Particule/Particule.h"
#include <map>
#include <cmath>
#include "../Triplet/Triplet.h"


class Grille {
    private:
        std::map<Triplet, std::vector<Particule*>> grille;
        double taille_case;
    public:
        Grille(std::vector<Particule*> particules = {}) {for (Particule* p : particules) ajouterParticule(p); if(particules.size() == 0) {taille_case = 1;} else {taille_case = sigmaMax(particules);}} //done
        double sigmaMax(std::vector<Particule*> v) const {double sigma_max = 0; for(Particule* p:v) {sigma_max = std::max(sigma_max, p->getSigma());} return sigma_max;}
        void ajouterParticule(Particule* particule); // done 
        void retirerParticule(Particule* particule); //done
        void mettreAJour(Particule* particule) {retirerParticule(particule); ajouterParticule(particule);} // done
        std::vector<Particule*> getVoisins(const Particule* particule) const; // done
        const std::map<Triplet, std::vector<Particule*>>& getGrille() const { return grille;}
};
