#include "ParticuleNeige.h"




void ParticuleNeige::opere_sur(ParticuleNeige& p) {
    Vecteur3D e_i_j = this->get_position() - p.get_position();
    p.ajouteForce(forceLJ(e_i_j.norme(), epsilon, sigma)*(~e_i_j));
    this->ajouteForce(-forceLJ(e_i_j.norme(), epsilon, sigma)*(~e_i_j));
}
