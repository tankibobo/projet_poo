#include "Grille.h"
#include <algorithm>
#include <vector>
#include "../../../Particule/Particule.h"
#include "../Triplet/Triplet.h"


void Grille::ajouterParticule(Particule* particule) {
    int x = static_cast<int>(particule->get_position().getX()/taille_case);
    int y = static_cast<int>(particule->get_position().getY()/taille_case);
    int z = static_cast<int>(particule->get_position().getZ()/taille_case);
    particule->setX(x);
    particule->setY(y);
    particule->setZ(z);
    grille[Triplet(x, y, z)].push_back(particule);
}


void Grille::retirerParticule(Particule* particule) {
    int x = particule->getX();
    int y = particule->getY();
    int z = particule->getZ();
    std::vector<Particule*>& caze = grille[Triplet(x, y, z)];
    caze.erase(std::remove(caze.begin(), caze.end(), particule), caze.end());
    }


std::vector<Particule*> Grille::getVoisins(const Particule* particule) const {
    std::vector<Particule*> voisins;
    int x = particule->getX();
    int y = particule->getY();
    int z = particule->getZ();
    // O(1) pas O(n^3)
    for(int i = x-1; i <= x+1; i++) {
        for(int j = y-1; j <= y+1; j++) {
            for(int k = z-1; k <= z+1; k++) {
                Triplet t = {i, j, k};
                if(grille.count(t)) {
                    for(Particule* p : grille.at(t)) {
                        if(p != nullptr and p != particule) {
                            voisins.push_back(p);
                        }
                    }
                }
            }
        }
    }
    return voisins;
}
