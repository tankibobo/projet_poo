#include "ParticuleRoche.h"
#include "../ParticuleNeige/ParticuleNeige.h"
#include "../Constantes.h"

void ParticuleRoche::opere_sur(ParticuleNeige& p) {
    Vecteur3D e_i_j = this->get_position() - p.get_position();
    double eps_moyen = sqrt(epsilon*p.getEpsilon());
    double sig_moyen = (sigma + p.getSigma())/2.0;
    p.ajouteForce(forceLJ(e_i_j.norme(), eps_moyen, sig_moyen)*(~e_i_j));
    this->ajouteForce(-forceLJ(e_i_j.norme(), eps_moyen, sig_moyen)*(~e_i_j));
}

void ParticuleRoche::opere_sur(ParticuleRoche& p) {
    Vecteur3D e_i_j = this->get_position() - p.get_position();
    double x = e_i_j.norme()/sigma;
    if(x<Constantes::x_repulsif) { 
        p.ajouteForce(forceLJ(e_i_j.norme(), epsilon, sigma)*(~e_i_j));
        this->ajouteForce(-forceLJ(e_i_j.norme(), epsilon, sigma)*(~e_i_j));
    }
    return;
}