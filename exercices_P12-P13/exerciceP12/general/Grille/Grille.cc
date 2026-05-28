#include "Grille.h"
#include <algorithm>
#include <vector>
#include "Particule/Particule.h"

void Grille::ajouterParticule(Particule* particule) {
    int x = static_cast<int>(particule->get_position().getX()/taille_case - decalage_x);
    int y = static_cast<int>(particule->get_position().getY()/taille_case - decalage_y);
    int z = static_cast<int>(particule->get_position().getZ()/taille_case - decalage_z);
    particule->setX(x);
    particule->setY(y);
    particule->setZ(z);
    if (x < 0 or y < 0 or z < 0) {
        int minX = x;
        int minY = y;
        int minZ = z;
        for(Particule* p : getParticules()) {
            minX = std::min(minX, p->getX());
            minY = std::min(minY, p->getY());
            minZ = std::min(minZ, p->getZ());
        }
        decaler(minX, minY, minZ);
    }
    else if (x>=0 and y>=0 and z>=0 and x < grille.size() and y < grille[x].size() and z < grille[x][y].size()) {
        grille[x][y][z].push_back(particule);
    }
    else {
        agrandirGrille(particule);
    }
}

void Grille::retirerParticule(Particule* particule) {
    int x = particule->getX();
    int y = particule->getY();
    int z = particule->getZ();
    std::vector<Particule*>& caze = grille[x][y][z];
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
                if(i >= 0 and i < grille.size() and j >= 0 and j < grille[i].size() and k >= 0 and k < grille[i][j].size()) {
                    for(Particule* p : grille[i][j][k]) {
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
    int x = particule->getX();
    int y = particule->getY();
    int z = particule->getZ();
    if(x >= grille.size()) {
        grille.resize(x+1);
    }
    if(y >= grille[x].size()) {
        grille[x].resize(y+1);
    }
    if(z >= grille[x][y].size()) {
        grille[x][y].resize(z+1);
    }
    ajouterParticule(particule);
}

//cette fonction gère les cas où les coordonnées sont négatives O(n)
void Grille::decaler(int dx, int dy, int dz) {
    std::vector<Particule*> particules = getParticules();
    for(Particule* p : particules) {
        p->setX(p->getX() - dx);
        p->setY(p->getY() - dy);
        p->setZ(p->getZ() - dz);
    }
    grille.clear();
    for(Particule* p : particules) {
        ajouterParticule(p);
    }
}

std::vector<Particule*> Grille::getParticules() const {
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