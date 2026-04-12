// git pull [...] git add ., git commit -m "message", git push
#include <iostream>
#include "Particule.h"
#include <array>
#include "Constantes.h"
#include "Vecteur3D.h"
#include "Plan.h"
using namespace std;

ostream& operator<<(std::ostream& os, const Particule& p) {
os << "Pos: (" << p.get_position().getX() << " " << p.get_position().getY() << " " << p.get_position().getZ() << "), " << "V: (" << p.get_vitesse().getX() << " " << p.get_vitesse().getY() << " " << p.get_vitesse().getZ() << "), " << "M: " << p.getMasse() << ", M/V: " << p.getMasseV() << ", R: " << p.getRayon();
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
    if(vitesse.norme() <= (80.0*viscosite)/(3.0*masse_v_milieu*rayon)) {
        return (6.0*Constantes::pi*viscosite*rayon)*vitesse;
    }
    return (((9.0*Constantes::pi)/40.0)*rayon*rayon*masse_v_milieu*vitesse.norme())*vitesse;
}

void Particule::ajouteForce() {
    cout << "lambda*v: " << lambda_v() << endl;
    cout << "lambda: ";
    if(vitesse.norme() <= (80.0*viscosite)/(3.0*masse_v_milieu*rayon)) {
        cout << (6.0*Constantes::pi*viscosite*rayon) << endl;
    }
    else {
        cout << (((9.0*Constantes::pi)/40.0)*rayon*rayon*masse_v_milieu*vitesse.norme()) << endl;
    }
    cout << "v: " << vitesse.norme() << endl;
    cout << "limite: " << (80.0*viscosite)/(3.0*masse_v_milieu*rayon) << endl;
    cout << "masse_v_milieu: " << masse_v_milieu << ", viscosite: " << viscosite << ", rayon: " << rayon << endl;
    force += (getMasse() * Constantes::g - lambda_v());
    cout << (getMasse() * Constantes::g - lambda_v()) << endl;
}

void Particule::ajouteForce(const Particule& p) {
    Vecteur3D e_i_j = p.get_position() - position;
    force += ((24.0*epsilon*f(e_i_j.norme()/sigma))/(sigma*sigma))*(~e_i_j);
    cout << ((24.0*epsilon*f(e_i_j.norme()/sigma))/(sigma*sigma))*(~e_i_j) << endl;
}

void Particule::ajouteForce(const Obstacle& obstacle) {
    Vecteur3D proche = obstacle.PointPlusProche(position);
    Vecteur3D e_i_p = proche - position;
force += 2.0 * (24.0*epsilon*f(e_i_p.norme()/sigma))/(sigma*sigma) * (~e_i_p);
cout << 2.0 * (24.0*epsilon*f(e_i_p.norme()/sigma))/(sigma*sigma) * (~e_i_p) << endl;
}

void Particule::bouger(double t) {
    cout << "force: " << force << endl;
    vitesse += (t/getMasse())*force;
    position += {(t*vitesse).getX(), (t*vitesse).getY(), (t*vitesse).getZ()};
    force = Vecteur3D(0,0,0);
}