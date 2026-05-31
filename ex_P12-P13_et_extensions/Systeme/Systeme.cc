#include "Systeme.h"
#include <iostream>
#include "Constantes.h"
#include "../Particule/Particule.h"
#include "Obstacle/Obstacle.h"
#include "Source/Source.h"
#include "../Calcul/Calcul.h"
#include "../Calcul/CalculGrille.h"
#include "../Calcul/CalculNaif.h"
#include "exerciceP12/Grille/Grille.h"
#include <vector>

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
    for (Particule* p : particules) {
        p->ajouteForce();
        for (Obstacle* o : obstacles) p->ajouteForce(*o);
    }


    calcul->calculerForce(particules); //3e loi Newton et boucle deja incluses

    calcul->bouger(particules, Constantes::dt);

    // Chocs avec les obstacles
    for (Particule* p : particules)
        for (Obstacle* o : obstacles) o->collision(*p);

    size_t taille = particules.size();
    // Sources : création de nouvelles particules à chaque pas de temps
    for (Source* s : sources) s->creation(particules, Constantes::dt);
    for(size_t i(taille); i < particules.size(); i++) {
        calcul->ajouterPart(particules[i]);
    }
    temps += Constantes::dt;
}


Systeme::~Systeme() {
    for (Particule* p : particules) delete p;
    for (Obstacle* o : obstacles) delete o;
    for (Source* s : sources) delete s;
    delete calcul;
}

void Systeme::grilleSysteme(bool b, std::vector<Particule*>& v) {
    if(b) {
        calcul = new CalculGrille(new Grille(v));
    }
    else {
        calcul = new CalculNaif;
    }
}