#include "Grille.h"
#include <algorithm>
#include <vector>
#include "../../Particule/Particule.h"
#include "../Triplet/Triplet.h"


void Grille::ajouterParticule(Particule* particule) {
    int x = (troncature(particule->get_position().getX()/taille_case));
    int y = (troncature(particule->get_position().getY()/taille_case));
    int z = (troncature(particule->get_position().getZ()/taille_case));
    particule->setX(x);
    particule->setY(y);
    particule->setZ(z);
    grille[Triplet(x, y, z)].push_back(particule);
}


void Grille::retirerParticule(Particule* particule) {
    int x = particule->getXGrille();
    int y = particule->getYGrille();
    int z = particule->getZGrille();
    Triplet cle(x,y,z);
    auto itMap = grille.find(cle);
    if (itMap != grille.end()) { //la case existe?
        std::vector<Particule*>& caze = itMap->second; //valeur de la case x,y,z

        auto itParticule = std::find(caze.begin(), caze.end(), particule);
        if (itParticule != caze.end()) {
            *itParticule = caze.back();
            caze.pop_back();
        }
        if (caze.empty()) grille.erase(itMap); // supprimer l'entrée vide
    }
}


std::vector<Particule*> Grille::getVoisins(const Particule* particule) const {
    std::vector<Particule*> voisins;
    int x = particule->getXGrille();
    int y = particule->getYGrille();
    int z = particule->getZGrille();
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
