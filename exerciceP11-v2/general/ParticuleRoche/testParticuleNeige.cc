// fonctionne et cmake verifié, donne les memes resultats que testParticule.cc
#include "ParticuleNeige.h"
#include "../Constantes.h"
#include <iostream>
using namespace std;

int main() {

    // constructeurs
    ParticuleNeige p1(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleNeige p2(1.0, 0.0, 0.0,  0.0, 0.2, 0.0,  12.5, 0.15, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleNeige p3(0.0, 0.0, 1.0,  0.0, 0.0, -0.05, 12.5, 0.1,  Constantes::viscosite_air, Constantes::mv_air);

    // copie
    ParticuleNeige p4(p1); 

    cout << "p1 : " << p1 << endl;
    cout << "p2 : " << p2 << endl;
    cout << "p3 : " << p3 << endl;

    cout << "p4 (copie) : " << p4 << endl;

    // ajoute force "perso"
    cout << "Force perso puis bouger" << endl;
    p1.ajouteForce(); // grace au using dans PNeige

    p1.bouger(Constantes::dt);
    cout << p1 << endl;

    // ajoute force interaction
    cout << "Force d'interaction p2 sur p3 (=p3 sur p2 à retenir)" << endl;
    cout << "p3 avant : " << p3 << endl;
    p3.ajouteForce(p2);
    p3.bouger(Constantes::dt);
    cout << "p3 après dt: " << p3 << endl;

    return 0;
}
