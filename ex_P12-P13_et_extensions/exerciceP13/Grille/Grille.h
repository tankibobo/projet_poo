#pragma once
#include <vector>
#include "../../Particule/Particule.h"
#include <map>
#include <cmath>
#include "../Triplet/Triplet.h"


class Grille {
    private:
        std::map<Triplet, std::vector<Particule*>> grille;
        double taille_case;
    public:
        Grille(std::vector<Particule*> particules = {}) {if(particules.size() == 0) {taille_case = 1;} else {taille_case = sigmaMax(particules);for (Particule* p : particules) ajouterParticule(p);}} //done
        double sigmaMax(std::vector<Particule*> v) const {double sigma_max = 0; for(Particule* p:v) {sigma_max = std::max(sigma_max, p->getSigma());} return sigma_max;}
        void ajouterParticule(Particule* particule); // done 
        void retirerParticule(Particule* particule); //done
        void mettreAJour(Particule* particule) {retirerParticule(particule); ajouterParticule(particule);} // done
        std::vector<Particule*> getVoisins(const Particule* particule) const; // done
        const std::map<Triplet, std::vector<Particule*>>& getGrille() const { return grille;}
        int troncature(double x) { int q = static_cast<int>(x); if(q>x) q--;return q;} // arrondi en dessous pour les nombres négatifs et positifs
};
