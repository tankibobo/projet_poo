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
        Grille(std::vector<Particule*> particules, int dX = 0, int dY = 0, int dZ = 0): taille_case(2*particules[0]->getSigma()), decalage_x(dX), decalage_y(dY), decalage_z(dZ) {
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
