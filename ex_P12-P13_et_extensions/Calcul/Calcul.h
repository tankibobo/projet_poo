#pragma once
#include <vector>

class Particule;

class Calcul { //superclasse qui gère le calcul de la force avec/sans grille
    public:
       virtual void calculerForce(const std::vector<Particule*>& particules) = 0;
       virtual void bouger(std::vector<Particule*>& particules, double dt) = 0;
       virtual void ajouterPart(Particule* p) = 0;

       virtual ~Calcul() = default;
};
