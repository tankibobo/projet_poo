#pragma once
#include <vector>
#include <ostream>
#include "Obstacle/Obstacle.h"
#include "Source/Source.h"
#include "Dessinable/Dessinable.h"
#include "Plan/Plan.h"

class Calcul;
class Particule;

class Systeme: public Dessinable {
    public:
    // constructeurs
        Systeme() : temps(0) {};
        Systeme(const unsigned int& p, const unsigned int& o, const unsigned int& s, Calcul* calc) : temps(0) {particules.reserve(p);obstacles.reserve(o);sources.reserve(s); calcul = calc;};
        Systeme(const std::vector<Particule*>& p, const std::vector<Obstacle*>& o, const std::vector<Source*>& s, Calcul* calc) : temps(0) {particules = p; obstacles = o; sources = s; calcul = calc;};
        Systeme(const double& t, const unsigned int& p, const unsigned int& o, const unsigned int& s, Calcul* calc) : temps(t) {particules.reserve(p);obstacles.reserve(o);sources.reserve(s); calcul = calc;};
        Systeme(const double& t) : temps(t) {};
    // fonctions d'ajout
        void ajoute_particule(Particule* p) {particules.push_back(p);}
        void ajoute_obstacle(Obstacle* o) {obstacles.push_back(o);}
        void ajoute_source(Source* s) {sources.push_back(s);}
    // evolution
        void evolue(); 
    // get 
        double getTemps() const {return temps;}
        const std::vector<Particule*>& getParticules() const {return particules;}
        const std::vector<Obstacle*>& getObstacles() const {return obstacles;}
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
        std::vector<Obstacle*> obstacles;
        std::vector<Source*> sources;
        double temps;
        Calcul* calcul;
};

std::ostream& operator<<(std::ostream& os, const Systeme& s);