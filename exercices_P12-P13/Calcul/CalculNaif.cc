#include "CalculNaif.h"
#include <vector>
#include "../Particule/Particule.h"

<<<<<<< Updated upstream

void CalculNaif::calculerForce(const std::vector<Particule*>& particules) {
=======
void CalculNaif::calculerForce(const std::vector<Particule*>& particules) { // classique, même que pour les autres exos
>>>>>>> Stashed changes
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
