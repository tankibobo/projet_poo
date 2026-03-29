#include "Particule.h"
#include "Obstacle.h"
#include "Source.h"
#include <vector>
#include <ostream>
#include "Dessinable.h"
#pragma once

class Systeme: public Dessinable {
    public:
        Systeme() : temps(0) {};
        Systeme(const unsigned int& p, const unsigned int& o, const unsigned int& s) : temps(0) {particules.reserve(p);obstacles.reserve(o);sources.reserve(s);};
        Systeme(const double& t, const unsigned int& p, const unsigned int& o, const unsigned int& s) : temps(t) {particules.reserve(p);obstacles.reserve(o);sources.reserve(s);};
        Systeme(const double& t) : temps(t) {};
        void ajoute_particule(Particule* p) {particules.push_back(p);}
        void ajoute_obstacle(Obstacle* o) {obstacles.push_back(o);} //pot. a moidifer si on trovue un moyen de distinguer els sous classes par une fonction c++
        void ajoute_source(Source* s) {sources.push_back(s);}
        double getTemps() const {return temps;}
        std::vector<Particule*> getParticules() const {return particules;}
        std::vector<Obstacle*> getObstacles() const {return obstacles;}
        std::vector<Source*> getSources() const {return sources;}
    private:
        std::vector<Particule*> particules;
        std::vector<Obstacle*> obstacles;
        std::vector<Source*> sources;
        double temps;
};

std::ostream& operator<<(std::ostream& os, const Systeme& s);