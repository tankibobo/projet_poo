#pragma once
#include "Calcul.h"
#include <vector>
#include "../Particule/Particule.h"


class Grille;

class CalculGrille : public Calcul { // calcul pour les grilles
    private:
        Grille* grille; 
    public:
        CalculGrille(Grille* g) : grille(g) {}
        virtual void calculerForce(const std::vector<Particule*>& particules) override; // calculer la force pour chaque agent
        virtual void bouger(std::vector<Particule*>& particules, double dt) override; // bouger les agents 
        virtual void ajouterPart(Particule* p) override;
        ~CalculGrille();
};
