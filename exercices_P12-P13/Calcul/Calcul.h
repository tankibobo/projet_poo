#pragma once
#include <vector>
#include "../Particule/Particule.h"


class Calcul {
    public:
       virtual void calculerForce(const std::vector<Particule*>& particules) = 0;
       virtual void bouger(std::vector<Particule*>& particules, double dt) = 0;
       virtual ~Calcul() = default;
};
