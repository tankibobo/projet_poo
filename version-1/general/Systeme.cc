#include "Systeme.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Systeme& s) {
    std::vector<Particule*> p(s.getParticules());
    std::vector<Plan*> o(s.getObstacles());
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

Systeme::~Systeme() {
    for (Particule* p : particules) delete p;
    for (Plan* o : obstacles) delete o;
    for (Source* s : sources) delete s;
}