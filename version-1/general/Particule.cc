// git pull [...] git add ., git commit -m "message", git push
#include <iostream>
#include "Particule.h"
#include <array>
#include <cmath>
#include "Constantes.h"
using namespace std;

ostream& operator<<(std::ostream& os, const Particule& p) {
os << "Position: (" << p.get_position()[0] << " " << p.get_position()[1] << " " << p.get_position()[2] << "), " << "Vitesse: (" << p.get_vitesse().getX() << " " << p.get_vitesse().getY() << " " << p.get_vitesse().getZ() << "), " << "Masse: " << p.getMasse() << ", Masse volumique: " << p.getMasseV() << ", Rayon: " << p.getRayon() << std::endl;
    return os;
}
double Particule::f(const double& x) {
    if(x <= 1) {
        return -1;
    }
    if(x >= 2) {
        return 1;
    }
    return ((pow(x, 6)-2)/pow(x, 13));
}
Vecteur3D Particule::lambda() const {
    if(vitesse.norme() <= (80*viscosite)/(3*masse_v_milieu*rayon)) {
        return (6*M_PI*viscosite*rayon)*vitesse;
    }
    return (((9*M_PI)/40)*rayon*rayon*masse_v_milieu*vitesse.norme())*vitesse;
}

void Particule::ajoute_force() {
    force += (getMasse() * Constantes::g - lambda());
}

void Particule::ajoute_force(const Particule& p) {
    Vecteur3D e_i_j = Vecteur3D(p.get_position()[0] - position[0], p.get_position()[1] - position[1], p.get_position()[2] - position[2]);
    force += ((24*epsilon*f(e_i_j.norme()/sigma))/(sigma*sigma))*(~e_i_j);
}

void Particule::bouger(double t) {
    vitesse += (t/getMasse())*(force + getMasse()*Constantes::g - lambda());
    position = {(t*vitesse).getX(), (t*vitesse).getY(), (t*vitesse).getZ()};
    force = Vecteur3D(0,0,0);
}