#pragma once
#include <vector>
#include <ostream>
#include "Obstacle/Obstacle.h"
#include "Source/Source.h"
#include "Dessinable/Dessinable.h"
#include "SupportADessin/SupportADessin.h"


class Particule;


class Systeme: public Dessinable {
    public:
    // constructeurs
        Systeme() : temps(0) {};
        Systeme(unsigned int p, unsigned int o, unsigned int s) : temps(0) {particules.reserve(p);obstacles.reserve(o);sources.reserve(s);};
        Systeme(const std::vector<Particule*>& p, const std::vector<Obstacle*>& o, const std::vector<Source*>& s) : temps(0) {particules = p; obstacles = o; sources = s;};
        Systeme(double t, unsigned int p, unsigned int o, unsigned int s) : temps(t) {particules.reserve(p);obstacles.reserve(o);sources.reserve(s);};
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
    // copie (pas de copie d'un système)
        Systeme(const Systeme&) = delete;
        Systeme& operator=(const Systeme&) = delete;
    // destructeur
        ~Systeme();
    private:
        std::vector<Particule*> particules;
        std::vector<Obstacle*> obstacles;
        std::vector<Source*> sources;
        double temps;
};


std::ostream& operator<<(std::ostream& os, const Systeme& s);
