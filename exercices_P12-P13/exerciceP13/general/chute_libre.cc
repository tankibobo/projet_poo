#include "../../Systeme/Systeme.h"
#include "../../Particule/Particule.h"
#include "../texte/TextViewer.h"
#include <iostream>
 

int main() {
    Particule* p = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0,0,0},{5.0, 0.0, 7.0});
 

    Systeme s;
    s.ajoute_particule(p);
 

    TextViewer tv(std::cout);
 

    std::cout << "Le système est composé des "
              << s.getParticules().size() << " particule(s) suivante(s) :" << std::endl;
    s.dessine_sur(tv);
    std::cout << std::endl;
 

    constexpr double dt = 0.01;
 

    for (int i = 0; i < 15; ++i) {
        for (Particule* part : s.getParticules()) {
            part->ajouteForce();
            part->bouger(dt);
        }
        s.dessine_sur(tv);
        std::cout << std::endl;
    }
 

    return 0;
}
