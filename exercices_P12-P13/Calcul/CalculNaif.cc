#include "CalculNaif.h"
#include <vector>
#include "../Particule/Particule.h"


void CalculNaif::calculerForce(const std::vector<Particule*>& particules) {
    for (size_t i(0); i < particules.size(); ++i) {
        for (size_t j(i + 1); j < particules.size(); ++j) {
            particules[i]->ajouteForce(*particules[j]);
        }
    }
}


void CalculNaif::bouger(std::vector<Particule*>& particules, double dt) {
    for (Particule* p : particules) {
        p->bouger(dt);
    }
}
