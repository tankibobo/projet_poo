#include "Systeme/Systeme.h"
#include <iostream>
#include "Constantes.h"
#include "Particule/Particule.h"
#include "Obstacle/Obstacle.h"
#include "Source/Source.h"
#include "../Agent/Agent.h"


std::ostream& operator<<(std::ostream& os, const Systeme& s) {
    std::vector<Particule*> p(s.getParticules());
    std::vector<Obstacle*> o(s.getObstacles());
    std::vector<Source*> src(s.getSources());


    os << "Le système a " << p.size() << " particules, " << o.size() << " obstacles et " << src.size() << " sources." << std::endl;
    os << std::endl;


    os << "Particules : " << std::endl;
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


void Systeme::evolue() {
    // force des obstacles et des frottements
    for (Particule* p : particules) {
        p->ajouteForce();
        for (Obstacle* o : obstacles) p->ajouteForce(*o);
    }

    // force d'interaction entre les particules
    for (size_t i(0); i < particules.size(); ++i) { //la boucle exclut les particules "déjà évaluées" car ajouteForce applque la 3e loi de Newton
        for (size_t j(i + 1); j < particules.size(); ++j) {
            particules[i]->ajouteForce(*particules[j]);//3e loi Newton deja incluse
        }
    }


    for (Particule* p : particules) p->bouger(Constantes::dt);


    // Chocs élastiques : inversion des vitesses si particule dans un obstacle
    for (Particule* p : particules)
        for (Obstacle* o : obstacles) o->collision(*p);


    // Sources : création de nouvelles particules à chaque pas de temps
    for (Source* s : sources) s->creation(particules, Constantes::dt);


    temps += Constantes::dt;
}


Systeme::~Systeme() {
    for (Particule* p : particules) delete p;
    for (Obstacle* o : obstacles) delete o;
    for (Source* s : sources) delete s;
}
