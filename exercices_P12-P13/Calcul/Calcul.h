#pragma once
#include <vector>

<<<<<<< Updated upstream

class Calcul {
=======
class Particule;

class Calcul { //superclasse qui gère le calcul de la force avec/sans grille
>>>>>>> Stashed changes
    public:
       virtual void calculerForce(const std::vector<Particule*>& particules) = 0;
       virtual void bouger(std::vector<Particule*>& particules, double dt) = 0;
       virtual void ajouterPart(Particule* p) = 0;

       virtual ~Calcul() = default;
};
