#include "Obstacle.h"
#include "../Particule/Particule.h"
#include "../ParticuleNeige/ParticuleNeige.h"

std::ostream& operator<<(std::ostream& os, const Obstacle& o) {
    return o.affiche(os);
}

void Obstacle::opere_sur(ParticuleNeige& p) {force(p);}

void Obstacle::force(Particule& p) const {;
    Vecteur3D proche = PointPlusProche(p.get_position());
    Vecteur3D e_i_p = proche - p.get_position();
    p.ajouteForce(2.0 * (24.0*p.getEpsilon()*p.f(e_i_p.norme()/p.getSigma())/(p.getSigma()*p.getSigma())) * (~e_i_p));
}