// fonctionne et cmake verifié, donne les memes resultats que testParticule.cc
#include "../ParticuleNeige/ParticuleNeige.h"
#include "../ParticuleRoche/ParticuleRoche.h"
#include "Constantes.h"
#include <iostream>


int main() {


    // constructeurs
    ParticuleNeige p1(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleRoche p2(12.5, 0.15, Constantes::viscosite_air, Constantes::mv_air, {1.0, 0.0, 0.0}, {0.0, 0.2, 0.0});
    ParticuleNeige p3(12.5, 0.1, Constantes::viscosite_air, Constantes::mv_air, {0.0, 0.0, 1.0}, {0.0, 0.0, -0.05});


    // copie
    ParticuleNeige p4(p1);
    ParticuleRoche p5(p2);


    std::cout << "p1 (neige) : " << p1 << std::endl;
    std::cout << "p2 (roche) : " << p2 << std::endl;
    std::cout << "p3 (neige) : " << p3 << std::endl;


    std::cout << "p4 (neige, copie) : " << p4 << std::endl;
    std::cout << "p5 (roche, copie) : " << p5 << std::endl;


    // ajoute force interaction
    std::cout << "Force d'interaction p2 sur p3 (=p3 sur p2 dans ce modele)" << std::endl;
    std::cout << "___ avant ____" << std::endl;
    std::cout << "p3 avant : " << p3 << std::endl;
    std::cout << "p2 avant : " << p2 << std::endl;
    p3.ajouteForce(p2);
    p3.bouger(Constantes::dt);
    p2.bouger(Constantes::dt);
    std::cout << "p3 après dt: " << p3 << std::endl;
    std::cout << "p2 après dt: " << p2 << std::endl;


    std::cout << "Force d'interaction p2 sur p5 (=p5 sur p2 dans ce modele)" << std::endl;
    std::cout << "___ avant ____" << std::endl;
    std::cout << "p5 avant : " << p5 << std::endl;
    std::cout << "p2 avant : " << p2 << std::endl;
    p5.ajouteForce(p2);
    p5.bouger(Constantes::dt);
    p2.bouger(Constantes::dt);
    std::cout << "p5 après dt: " << p5 << std::endl;
    std::cout << "p2 après dt: " << p2 << std::endl;

<<<<<<< Updated upstream

    // cas limites (particules a la meme position). normalement, par sécurité, deux particules exactement au même endroit ne s'appliquent aucune force (évite le NaN)
=======
    // cas limites (particules a la meme position).
>>>>>>> Stashed changes


    ParticuleRoche p6(p2);


    std::cout << "Force d'interaction p2 sur p6 (=p6 sur p2 dans ce modele)" << std::endl;
    std::cout << "p6 avant : " << p6 << std::endl;
    std::cout << "p2 avant : " << p2 << std::endl;
    p6.ajouteForce(p2);
    p6.bouger(Constantes::dt);
    p2.bouger(Constantes::dt);
    std::cout << "p6 après dt: (doit être les mêmes)" << p6 << std::endl;
    std::cout << "p2 après dt: " << p2 << std::endl;


    std::cout << "Force d'interaction p4 sur p1 (=p1 sur p4 dans ce modele)" << std::endl;
    std::cout << "p1 avant : " << p1 << std::endl;
    std::cout << "p4 avant : " << p4 << std::endl;
    p1.ajouteForce(p4);
    p1.bouger(Constantes::dt);
    p4.bouger(Constantes::dt);
    std::cout << "p1 après dt: " << p1 << std::endl;
    std::cout << "p4 après dt: " << p4 << std::endl;


    return 0;
}
