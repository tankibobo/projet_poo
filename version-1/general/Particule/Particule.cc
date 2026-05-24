#include <iostream>
#include <array>
#include "Particule.h"
#include "Constantes.h"
#include "Vecteur3D/Vecteur3D.h"
#include "Plan/Plan.h"

std::ostream& operator<<(std::ostream& os, const Particule& p) {
os << "Pos: (" << p.get_position().getX() << " " << p.get_position().getY() << " " << p.get_position().getZ() << "), " << "V: (" << p.get_vitesse().getX() << " " << p.get_vitesse().getY() << " " << p.get_vitesse().getZ() << "), " << "M: " << p.getMasse() << ", M/V: " << p.getMasseV() << ", R: " << p.getRayon();
    return os;
}

double Particule::f(const double& x) {
    if(x <= 1) {
        return -1;
    }
    if(x >= 2) {
        return 0;
    }
    return ((std::pow(x, 6) - 2.0) / std::pow(x, 13));
}

Vecteur3D Particule::lambda_v() const {
    if(vitesse.norme() <= (80.0*viscosite)/(3.0*masse_v_milieu*rayon)) {
        return (6.0*Constantes::pi*viscosite*rayon)*vitesse;
    }
    return (((9.0*Constantes::pi)/40.0)*rayon*rayon*masse_v_milieu*vitesse.norme())*vitesse;
}

void Particule::ajouteForce() {
    force += ((getMasse() * Constantes::g) - lambda_v());
}

void Particule::ajouteForce(Particule& p) {
    Vecteur3D e_i_j = p.get_position() - position;
    double d = e_i_j.norme();
    force += forceLJ(d) * (~e_i_j);
    p.ajouteForce(-(forceLJ(d) * (~e_i_j))); //3e loi Newton
}

void Particule::ajouteForce(const Obstacle& obstacle) {;
    Vecteur3D proche = obstacle.PointPlusProche(position);
    Vecteur3D e_i_p = proche - position;
    force += 2.0 * forceLJ(e_i_p.norme()) * (~e_i_p);
}

void Particule::bouger(double dt) {
    vitesse += (dt/getMasse())*force;
    position += dt*vitesse;
    force = Vecteur3D(0,0,0);
}