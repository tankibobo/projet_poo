// fonctionne et cmake verifié, donne les memes resultats que testParticule.cc
#include "ParticuleNeige.h"
#include "Constantes.h"


#include <iostream>


int main() {


    // constructeurs
    ParticuleNeige p1(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleNeige p2(12.5, 0.15, Constantes::viscosite_air, Constantes::mv_air, {1.0, 0.0, 0.0}, {0.0, 0.2, 0.0});
    ParticuleNeige p3(12.5, 0.1, Constantes::viscosite_air, Constantes::mv_air, {0.0, 0.0, 1.0}, {0.0, 0.0, -0.05});


    // copie
    ParticuleNeige p4(p1);


    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;
    std::cout << "p3 : " << p3 << std::endl;


    std::cout << "p4 (copie) : " << p4 << std::endl;


    // ajoute force "perso"
    std::cout << "Force perso puis bouger" << std::endl;
    p1.ajouteForce(); // grace au using dans PNeige


    p1.bouger(Constantes::dt);
    std::cout << p1 << std::endl;


    // ajoute force interaction
    std::cout << "Force d'interaction p2 sur p3 (=p3 sur p2 à retenir)" << std::endl;
    std::cout << "p3 avant : " << p3 << std::endl;
    p3.ajouteForce(p2);
    p3.bouger(Constantes::dt);
    std::cout << "p3 après dt: " << p3 << std::endl;


    return 0;
}
