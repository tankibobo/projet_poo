#include "Systeme.h"
#include <iostream>
#include "../Constantes.h"

std::ostream& operator<<(std::ostream& os, const Systeme& s) {
    std::vector<Particule*> p(s.getParticules());
    std::vector<Obstacle*> o(s.getObstacles());
    std::vector<Source*> src(s.getSources());

    os << "Le système a " << p.size() << " particules, " << o.size() << " obstacles et " << src.size() << " sources." << std::endl;
    os << std::endl;

    os << "Particules : " <<  std::endl;
    for(size_t i(0); i < p.size(); i++) {
        os << "- " << *p[i] << std::endl;
    }

    os << std::endl;
    os << "Obstacles : " << std::endl;
    for(size_t i(0); i < o.size(); i++) {
        os << "- " << *o[i] << std::endl;
    }

    os << std::endl;
    os << "Sources : " << std::endl;
    for(size_t i(0); i < src.size(); i++) {
        os << "- " << *src[i] << std::endl;
    }

    return os;
}
// Optimisation par la 3e loi de Newton :
// chaque paire (i, j) n'est calculée qu'une seule fois → N(N-1)/2 calculs
// au lieu de N(N-1), soit un facteur 2 sur les forces inter-particulaires.
void Systeme::evolue() {
    // ── Étape 1 : forces individuelles (poids + frottement) et obstacles ─────
    for (Particule* p : particules) {
        p->ajouteForce();                               // force perso
        for (Obstacle* o : obstacles) p->ajouteForce(*o); // force de chaque obstacle
    }

    // ── Étape 2 : forces inter-particulaires (3e loi de Newton) ──────────────
    // F_{j→i} = forceLJ(|e_ij|) * ê_ij
    // F_{i→j} = −F_{j→i}   (action-réaction)
    for (size_t i(0); i < particules.size(); ++i) {
        for (size_t j(i + 1); j < particules.size(); ++j) {
            Vecteur3D e_ij = particules[j]->get_position()
                           - particules[i]->get_position();
            Vecteur3D f_ij = Particule::forceLJ(e_ij.norme()) * (~e_ij);
            particules[i]->ajouteForce( f_ij);  // force de j sur i
            particules[j]->ajouteForce(-f_ij);  // force de i sur j  (Newton 3)
        }
    }

    // ── Étape 3 : déplacement Euler-Cromer ───────────────────────────────────
    for (Particule* p : particules) p->bouger(Constantes::dt);
}

Systeme::~Systeme() {
    for (Particule* p : particules) delete p;
    for (Obstacle* o : obstacles) delete o;
    for (Source* s : sources) delete s;
}