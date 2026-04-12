#include "Systeme.h"
#include <iostream>
#include "Constantes.h"

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

void Systeme::evolue() {
    std::cout << "EVOLUE() : " << std::endl;
    int i(1);
    for (Particule* p : particules) {
        std::cout << "-------------------------------------- " << std::endl;
        std::cout << "Particule " << i << " : " << *p << std::endl;
        i++;
        std::cout << "Force personelle : " << p->lambda_v() << std::endl;
        p->ajouteForce();
        std::cout << "Force obstacle : " << p->lambda_v() << std::endl;
        for (Obstacle* o : obstacles) p->ajouteForce(*o);
        std::cout << "Forces particules : " << p->lambda_v() << std::endl;
        for (Particule* p2 : particules) if (p != p2) p->ajouteForce(*p2);
    }
    for (Particule* p : particules) p->bouger(Constantes::dt);
}

Systeme::~Systeme() {
    for (Particule* p : particules) delete p;
    for (Obstacle* o : obstacles) delete o;
    for (Source* s : sources) delete s;
}