// git pull [...] git add ., git commit -m "message", git push
#include <iostream>
#include "Particule.h"
#include <array>
#include "Constantes.h"
#include "Vecteur3D.h"
#include "Plan.h"
using namespace std;

ostream& operator<<(std::ostream& os, const Particule& p) {
os << "Pos: (" << p.get_position().getX() << " " << p.get_position().getY() << " " << p.get_position().getZ() << "), " << "V: (" << p.get_vitesse().getX() << " " << p.get_vitesse().getY() << " " << p.get_vitesse().getZ() << "), " << "M: " << p.getMasse() << ", M/V: " << p.getMasseV() << ", R: " << p.getRayon() << std::endl;
    return os;
}
double Particule::f(const double& x) {
    if(x <= 1) {
        return -1;
    }
    if(x >= 2) {
        return 1;
    }
    return ((puissance(x, 6)-2)/puissance(x, 13));
}
Vecteur3D Particule::lambda_v() const {
    if(vitesse.norme() <= (80*viscosite)/(3*masse_v_milieu*rayon)) {
        return (6*M_PI*viscosite*rayon)*vitesse;
    }
    return (((9*M_PI)/40)*rayon*rayon*masse_v_milieu*vitesse.norme())*vitesse;
}

void Particule::ajoute_force() {
    force += (getMasse() * Constantes::g - lambda_v());
}

void Particule::ajoute_force(const Particule& p) {
    Vecteur3D e_i_j = Vecteur3D(p.get_position().getX() - position.getX(), p.get_position().getY() - position.getY(), p.get_position().getZ() - position.getZ());
    force += ((24*epsilon*f(e_i_j.norme()/sigma))/(sigma*sigma))*(~e_i_j);
}

void Particule::ajoute_force(const Obstacle& obstacle) {
    Vecteur3D pos(position.getX(), position.getY(), position.getZ());
    Vecteur3D proche = obstacle.PointPlusProche(pos);
    Vecteur3D e_i_p = pos - proche;
force += 2.0 * (24*epsilon*f(e_i_p.norme()/sigma)/(sigma*sigma)) * (~e_i_p);
}

void Particule::bouger(double t) {
    vitesse += (t/getMasse())*(force + getMasse()*Constantes::g - lambda_v());
    // faudrait pas plus ajouter a la position? en mode += et pas la réinitialier? A verifer
    position = {(t*vitesse).getX(), (t*vitesse).getY(), (t*vitesse).getZ()};
    force = Vecteur3D(0,0,0);
}