#include "Particule.h"
#include "Obstacle.h"
#include "Source.h"
#include <vector>
#include <ostream>
#include "Dessinable.h"
#pragma once

class Systeme: public Dessinable {
    public:
    // constructeurs
        Systeme() : temps(0) {};
        Systeme(const unsigned int& p, const unsigned int& o, const unsigned int& s) : temps(0) {particules.reserve(p);obstacles.reserve(o);sources.reserve(s);};
        Systeme(const std::vector<Particule*>& p, const std::vector<Plan*>& o, const std::vector<Source*>& s) : temps(0) {particules = p; obstacles = o; sources = s;};
        Systeme(const double& t, const unsigned int& p, const unsigned int& o, const unsigned int& s) : temps(t) {particules.reserve(p);obstacles.reserve(o);sources.reserve(s);};
        Systeme(const double& t) : temps(t) {};
    // fonctions d'ajout
        void ajoute_particule(Particule* p) {particules.push_back(p);}
        void ajoute_obstacle(Plan* o) {obstacles.push_back(o);} //pot. a moidifer si on trovue un moyen de distinguer els sous classes par une fonction c++
        void ajoute_source(Source* s) {sources.push_back(s);}
    // get 
        double getTemps() const {return temps;}
        const std::vector<Particule*>& getParticules() const {return particules;}
        const std::vector<Plan*>& getObstacles() const {return obstacles;}
        const std::vector<Source*>& getSources() const {return sources;}
    // dessin    
        virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); }
    // copie
        Systeme(const Systeme&) = delete;
        Systeme& operator=(const Systeme&) = delete;
    // destructeur
        ~Systeme();
    private:
        std::vector<Particule*> particules;
        std::vector<Plan*> obstacles;
        std::vector<Source*> sources;
        double temps;
};

std::ostream& operator<<(std::ostream& os, const Systeme& s);