#pragma once
#include <vector>
#include "Particule/Particule.h"

class Grille {
    private:
        std::vector<std::vector<std::vector<std::vector<Particule*>>>> grille;
        double taille_case;
        int decalage_x;
        int decalage_y;
        int decalage_z;
    public:
        Grille() = delete;
        Grille(std::vector<Particule*> particules, int decalage_x = 0, int decalage_y = 0, int decalage_z = 0): taille_case(2*particules[0]->getSigma()), decalage_x(decalage_x), decalage_y(decalage_y), decalage_z(decalage_z) {
            int maxX(0);
            int maxY(0); 
            int maxZ(0); 
            for (Particule* p : particules) {
                maxX = std::max(maxX, static_cast<int>(p->get_position().getX()/taille_case));
                maxY = std::max(maxY, static_cast<int>(p->get_position().getY()/taille_case));
                maxZ = std::max(maxZ, static_cast<int>(p->get_position().getZ()/taille_case));
            }
            grille.resize(maxX+1, std::vector<std::vector<std::vector<Particule*>>>(maxY+1, std::vector<std::vector<Particule*>>(maxZ+1)));
            for (Particule* p : particules) ajouterParticule(p);
        } //done
        void ajouterParticule(Particule* particule); // done 
        void retirerParticule(Particule* particule); //done
        void mettreAJour(Particule* particule) {retirerParticule(particule); ajouterParticule(particule);} // done
        std::vector<Particule*> getVoisins(const Particule* particule) const; // done
        void agrandirGrille(Particule* particule); // done
        void decaler(int x, int y, int z); // done
        std::vector<Particule*> getParticules() const; // done
};