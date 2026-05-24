#include <ostream>

#include "Obstacle.h"
#include "Vecteur3D/Vecteur3D.h"
#include "../ParticuleNeige/ParticuleNeige.h"

std::ostream& operator<<(std::ostream& os, const Obstacle& o) {
    return o.affiche(os);
}

void Obstacle::opere_sur(ParticuleNeige& p) {
    Vecteur3D proche = PointPlusProche(p.get_position());
    Vecteur3D e_i_p = proche - p.get_position();
    p.ajouteForce(2.0 * p.forceLJ(e_i_p.norme(), p.getEpsilon(), p.getSigma()) * (~e_i_p));
}