#include "Systeme.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Systeme& s) {
    std::vector<Particule*> p(s.getParticules());
    std::vector<Obstacle*> o(s.getObstacles());
    std::vector<Source*> src(s.getSources());
    os << "Temps :" << s.getTemps() << std::endl; 
    os << "Particules : (quantité: " << p.size() << ")" <<  std::endl;
    for(size_t i(0); i < p.size(); i++) {
        os << "- " << *p[i] << std::endl;
    }
    os << "Obstacles : (quantité: " << o.size() << ")" << std::endl;
    for(size_t i(0); i < o.size(); i++) {
        os << "- " << *o[i] << std::endl;
    }
    os << "Sources : (quantité: " << src.size() << ")" << std::endl;
    for(size_t i(0); i < src.size(); i++) {
        os << "- " << *src[i] << std::endl;
    }
    return os;
}	