#include "../../Calcul/Calcul.h"
#include "../Grille/Grille.h"
#include "../../Calcul/CalculGrille.h"
#include <vector>
#include "../../Particule/Particule.h"


void CalculGrille::calculerForce(const std::vector<Particule*>& particules) {
    for (Particule* p : particules) {
        grille->retirerParticule(p);
        std::vector<Particule*> voisins = grille->getVoisins(p);
        for(Particule* v : voisins) {
            p->ajouteForce(*v);
        }
    }
    for(Particule* p : particules) {
        grille->ajouterParticule(p);
    }
}


void CalculGrille::bouger(std::vector<Particule*>& particules, double dt) {
    for (Particule* p : particules) {
        p->bouger(dt);
        grille->mettreAJour(p);
    }
}

void CalculGrille::ajouterPart(Particule* p) {grille->ajouterParticule(p);}

CalculGrille::~CalculGrille() {delete grille;}
