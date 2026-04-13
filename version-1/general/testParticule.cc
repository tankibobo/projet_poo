#include "Particule.h"
#include "Constantes.h"
#include <iostream>
using namespace std;

int main() {

    // === Création de particules (exemple de l'étape P5) ===
    // ρ1 = 1 mg/mm³, ρ2 = ρ3 = 12.5 mg/mm³ ; milieu = air
    Particule p1(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    Particule p2(1.0, 0.0, 0.0,  0.0, 0.2, 0.0,  12.5, 0.15, Constantes::viscosite_air, Constantes::mv_air);
    Particule p3(0.0, 0.0, 1.0,  0.0, 0.0, -0.05, 12.5, 0.1,  Constantes::viscosite_air, Constantes::mv_air);

    // === Copie ===
    Particule p4(p1);   // copie de p1

    cout << "Voici trois particules :" << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    cout << "Copie de la particule 1 :" << endl;
    cout << p4 << endl;

    // === Test ajouteForce (gravity + drag) ===
    cout << "\n--- Force perso (poids - frottement) ---" << endl;
    cout << "Avant ajouteForce() : force = (0 0 0)" << endl;
    p1.ajouteForce();
    // On ne peut pas lire force directement (privé),
    // mais bouger() l'applique : on teste en faisant bouger puis en affichant
    cout << "Après ajouteForce() et bouger(dt=0.001) :" << endl;
    p1.bouger(Constantes::dt);
    cout << p1 << endl;

    // === Test ajouteForce(Particule) ===
    cout << "\n--- Force inter-particulaire (p2 sur p3) ---" << endl;
    cout << "p3 avant : " << p3 << endl;
    p3.ajouteForce(p2);
    p3.bouger(Constantes::dt);
    cout << "p3 après un pas : " << p3 << endl;

    return 0;
}
