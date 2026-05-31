#pragma once
#include "Calcul.h"
#include <vector>

class CalculNaif : public Calcul { // calcul sans grille
    public:
        virtual void calculerForce(const std::vector<Particule*>& particules) override;
        virtual void bouger(std::vector<Particule*>& particules, double dt) override;
        virtual void ajouterPart(Particule*) override {}
};
