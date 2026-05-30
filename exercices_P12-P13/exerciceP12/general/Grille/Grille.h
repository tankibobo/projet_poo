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
        Grille(std::vector<Particule*> particules = {}, int dX = 0, int dY = 0, int dZ = 0): decalage_x(dX), decalage_y(dY), decalage_z(dZ) {
            if(particules.size() != 0) {
            taille_case = sigmaMax(particules);
            int minX(0), minY(0), minZ(0);
            int maxX(0), maxY(0), maxZ(0);
            for (Particule* p : particules) {
                int x = troncature(p->get_position().getX()/taille_case);
                int y = troncature(p->get_position().getY()/taille_case);
                int z = troncature(p->get_position().getZ()/taille_case);
                minX = std::min(minX, x);
                minY = std::min(minY, y);
                minZ = std::min(minZ, z);
                maxX = std::max(maxX, x);
                maxY = std::max(maxY, y);
                maxZ = std::max(maxZ, z);
            }
            decalage_x -= minX;
            decalage_y -= minY;
            decalage_z -= minZ;
            grille.resize(static_cast<size_t>(maxX - minX + 1), std::vector<std::vector<std::vector<Particule*>>>(static_cast<size_t>(maxY - minY + 1), std::vector<std::vector<Particule*>>(static_cast<size_t>(maxZ - minZ + 1))));
            for (Particule* p : particules) ajouterParticule(p);
<<<<<<< Updated upstream
        } //done
        void ajouterParticule(Particule* particule); // done
        void retirerParticule(Particule* particule); //done
        void mettreAJour(Particule* particule) {retirerParticule(particule); ajouterParticule(particule);} // done
        std::vector<Particule*> getVoisins(const Particule* particule) const; // done
        void agrandirGrille(Particule* particule); // done
        void decaler(int x, int y, int z); // done
        std::vector<Particule*> getParticules() const; // done
        int troncature(double x) { int q = static_cast<int>(x); if(q>x) q--;return q;}
};
=======
            }
            else { taille_case = 1;}
        } // test la taille que doit faire la grille car agrandirGrille() est lourde en calcul
        double sigmaMax(std::vector<Particule*> v) const {double sigma_max = 0; for(Particule* p:v) {sigma_max = std::max(sigma_max, p->getSigma());} return sigma_max;}
        std::vector<std::vector<std::vector<std::vector<Particule*>>>> getGrille() const {return grille;} //pour les tests
        void ajouterParticule(Particule* particule); // ajt une particule a la grille 
        void retirerParticule(Particule* particule); // retire de la grille
        void mettreAJour(Particule* particule) {retirerParticule(particule); ajouterParticule(particule);} // met a jour les coordonnées d'une part
        std::vector<Particule*> getVoisins(const Particule* particule) const; 
        void agrandirGrille(Particule* particule);
        void decaler(int x, int y, int z); // dans le cas ou une particule a des coordonnées négatives: on décale la grille pour inclure toutes les particules (très lourd en calcul)
        void refaireGrille(const std::vector<Particule*>& v) {for(Particule* p: v) ajouterParticule(p);}
        std::vector<Particule*> getParticules() const;
        int troncature(double x) { int q = static_cast<int>(x); if(q>x) q--;return q;} // arrondi en dessous pour les nombres négatifs et positifs
};
>>>>>>> Stashed changes
