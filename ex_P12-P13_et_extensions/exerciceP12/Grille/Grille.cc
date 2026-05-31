#include "Grille.h"
#include <algorithm>
#include <vector>
#include "Particule/Particule.h"
#include "../../Systeme/Systeme.h"

void Grille::ajouterParticule(Particule* particule) { 
    // on regarde les sigmas
    double taille_p = 2*particule->getSigma();
    if(taille_p > taille_case){
        taille_case=taille_p;
        refaireGrille(getParticules());
    }
    // on arrondi pour avoir des coordonnées dans la grille
    int x = troncature(particule->get_position().getXGrille()/taille_case + decalage_x);
    int y = troncature(particule->get_position().getYGrille()/taille_case + decalage_y);
    int z = troncature(particule->get_position().getZGrille()/taille_case + decalage_z);
    // si les coordonnées sont négatives, on prend les coordnnées minimums et on y décale l'origine de la grille
    if (x < 0 or y < 0 or z < 0) {
        int minX = x;
        int minY = y;
        int minZ = z;
        for(Particule* p : getParticules()) {
            minX = std::min(minX, (particule->get_position().getXGrille()/taille_case + decalage_x));
            minY = std::min(minY, (particule->get_position().getYGrille()/taille_case + decalage_y));
            minZ = std::min(minZ, (particule->get_position().getZGrille()/taille_case + decalage_z));
        }
        grille[0][0][0].push_back(particule);
        decaler(static_cast<int>(minX), static_cast<int>(minY), static_cast<int>(minZ));
        x = troncature(particule->get_position().getXGrille()/taille_case + decalage_x);
        y = troncature(particule->get_position().getYGrille()/taille_case + decalage_y);
        z = troncature(particule->get_position().getZGrille()/taille_case + decalage_z);
    }
    // si tout va bien, on ajt
    else if (x>=0 and y>=0 and z>=0 and static_cast<size_t>(x) < grille.size() and static_cast<size_t>(y) < grille[static_cast<size_t>(x)].size() and static_cast<size_t>(z) < grille[static_cast<size_t>(x)][static_cast<size_t>(y)].size()) {
        grille[static_cast<size_t>(x)][static_cast<size_t>(y)][static_cast<size_t>(z)].push_back(particule);
    }
    // si les particules sortent de la grille, on l'agrandit
    else {
        agrandirGrille(particule);
    }
    particule->setX(x);
    particule->setY(y);
    particule->setZ(z);
}


void Grille::retirerParticule(Particule* particule) {
    int x = particule->getXGrille();
    int y = particule->getYGrille();
    int z = particule->getZGrille();
    std::vector<Particule*>& caze = grille[static_cast<size_t>(x)][static_cast<size_t>(y)][static_cast<size_t>(z)];
    caze.erase(std::remove(caze.begin(), caze.end(), particule), caze.end()); // 'case' est apparemment deja reserve par c++
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
                if(i >= 0 and static_cast<size_t>(i) < grille.size() and j >= 0 and static_cast<size_t>(j) < grille[static_cast<size_t>(i)].size() and k >= 0 and static_cast<size_t>(k) < grille[static_cast<size_t>(i)][static_cast<size_t>(j)].size()) {
                    for(Particule* p : grille[static_cast<size_t>(i)][static_cast<size_t>(j)][static_cast<size_t>(k)]) {
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


void Grille::agrandirGrille(Particule* particule) {
    int x = (troncature(particule->get_position().getXGrille()/taille_case + decalage_x));
    int y = (troncature(particule->get_position().getYGrille()/taille_case + decalage_y));
    int z = (troncature(particule->get_position().getZGrille()/taille_case + decalage_z));
    if(static_cast<size_t>(x) >= grille.size()) {
        grille.resize(static_cast<size_t>(x+1));
    }
    if(static_cast<size_t>(y) >= grille[static_cast<size_t>(x)].size()) {
        grille[static_cast<size_t>(x)].resize(static_cast<size_t>(y+1));
    }
    if(static_cast<size_t>(z) >= grille[static_cast<size_t>(x)][static_cast<size_t>(y)].size()) {
        grille[static_cast<size_t>(x)][static_cast<size_t>(y)].resize(static_cast<size_t>(z+1));
    }
    grille[static_cast<size_t>(x)][static_cast<size_t>(y)][static_cast<size_t>(z)].push_back(particule);
    particule->setX(x);
    particule->setY(y);
    particule->setZ(z);
}


//cette fonction gère les cas où les coordonnées sont négatives O(n)
void Grille::decaler(int x, int y, int z) {
    std::vector<Particule*> particules = getParticules();
    //decalage est un attribut de grille, permet de garder le decalage
    decalage_x -= x;
    decalage_y -= y;
    decalage_z -= z;
    refaireGrille(particules);
}


std::vector<Particule*> Grille::getParticules() const {
    if(systeme != nullptr){return systeme->getParticules();}
    else {
        std::vector<Particule*> particules;
        for(const std::vector<std::vector<std::vector<Particule*>>>& i : grille) {
            for(const std::vector<std::vector<Particule*>>& j : i) {
                for(const std::vector<Particule*>& k : j) {
                    for(Particule* p : k) {
                        if(p != nullptr) {
                            particules.push_back(p);
                        }
                    }
                }
            }
        }
        return particules;
    }
}
