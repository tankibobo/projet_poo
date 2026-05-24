#pragma once
#include "Calcul.h"
#include <vector>
#include "../Particule/Particule.h"

class Grille;

class CalculGrille : public Calcul {
    private:
        Grille& grille;
    public:
        CalculGrille(Grille& g) : grille(g) {}
        virtual void calculerForce(const std::vector<Particule*>& particules) override;
        virtual void bouger(std::vector<Particule*>& particules, double dt) override;
};