// fonctionne et cmake verifié, donne les memes resultats que testParticule.cc
#include "../ParticuleNeige/ParticuleNeige.h"
#include "../ParticuleRoche/ParticuleRoche.h"
#include "../Constantes.h"
#include <iostream>
using namespace std;

int main() {

    // constructeurs
    ParticuleNeige p1(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleRoche p2(1.0, 0.0, 0.0,  0.0, 0.2, 0.0,  12.5, 0.15, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleNeige p3(0.0, 0.0, 1.0,  0.0, 0.0, -0.05, 12.5, 0.1,  Constantes::viscosite_air, Constantes::mv_air);

    // copie
    ParticuleNeige p4(p1); 
    ParticuleRoche p5(p2);

    cout << "p1 (neige) : " << p1 << endl;
    cout << "p2 (roche) : " << p2 << endl;
    cout << "p3 (neige) : " << p3 << endl;

    cout << "p4 (neige, copie) : " << p4 << endl;
    cout << "p5 (roche, copie) : " << p5 << endl;

    // ajoute force interaction
    cout << "Force d'interaction p2 sur p3 (=p3 sur p2 dans ce modele)" << endl;
    cout << "___ avant ____" << endl;
    cout << "p3 avant : " << p3 << endl;
    cout << "p2 avant : " << p2 << endl;
    p3.ajouteForce(p2);
    p3.bouger(Constantes::dt);
    p2.bouger(Constantes::dt);
    cout << "p3 après dt: " << p3 << endl;
    cout << "p2 après dt: " << p2 << endl;

    cout << "Force d'interaction p2 sur p5 (=p5 sur p2 dans ce modele)" << endl;
    cout << "___ avant ____" << endl;
    cout << "p5 avant : " << p5 << endl;
    cout << "p2 avant : " << p2 << endl;
    p5.ajouteForce(p2);
    p5.bouger(Constantes::dt);
    p2.bouger(Constantes::dt);
    cout << "p5 après dt: " << p5 << endl;
    cout << "p2 après dt: " << p2 << endl;

    // cas limites (particules a la meme position). normalement, par sécurité, deux particules exactement au même endroit ne s'appliquent aucune force (évite le NaN)

    ParticuleRoche p6(p2);

    cout << "Force d'interaction p2 sur p6 (=p6 sur p2 dans ce modele)" << endl;
    cout << "___ avant ____" << endl;
    cout << "p6 avant : " << p6 << endl;
    cout << "p2 avant : " << p2 << endl;
    p6.ajouteForce(p2);
    p6.bouger(Constantes::dt);
    p2.bouger(Constantes::dt);
    cout << "p6 après dt: " << p6 << endl;
    cout << "p2 après dt: " << p2 << endl;

    cout << "Force d'interaction p4 sur p1 (=p1 sur p4 dans ce modele)" << endl;
    cout << "___ avant ____" << endl;
    cout << "p1 avant : " << p1 << endl;
    cout << "p4 avant : " << p4 << endl;
    p1.ajouteForce(p4);
    p1.bouger(Constantes::dt);
    p4.bouger(Constantes::dt);
    cout << "p1 après dt: " << p1 << endl;
    cout << "p4 après dt: " << p4 << endl;

    return 0;
}
