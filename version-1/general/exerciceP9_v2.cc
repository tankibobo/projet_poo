// SIMULATION D'EVOLUTION GRAPHIQUE, FIN SEMAINE 6
// fonctionne et cmake verifié
#include "Systeme/Systeme.h"
#include "../texte/TextViewer.h"   // ← ajout P9 : visualisation en mode texte
#include <cmath>
#include <iostream>
 
int main() {
    // ── Particules aux sommets du tétraèdre régulier d'arête 1 mm ────────────
    // Constructeur utilisé : Particule(x, y, z, mv, r, visc, mv_milieu)
    //                        → vitesse initiale nulle
    Particule* p1 = new Particule(
        1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air
    );  // pos = (0, 0, 0)
    Particule* p2 = new Particule(
        1.0, 0.0, 0.0,
        1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air
    );  // pos = (1, 0, 0)
    Particule* p3 = new Particule(
        0.5, sqrt(3.0)/2.0, 0.0,
        1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air
    );  // pos = (1/2, √3/2, 0)
    Particule* p4 = new Particule(
        0.5, sqrt(3.0)/6.0, sqrt(6.0)/3.0,
        1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air
    );  // pos = (1/2, √3/6, √6/3)
 
    // ── Obstacle : plan z = -0.9, normale (0,0,1) ────────────────────────────
    Plan* o1 = new Plan(0.0, 0.0, -0.9, 0.0, 0.0, 1.0);
 
    Systeme s({p1, p2, p3, p4}, {o1}, {});
 
    // ── Visualisation en mode texte (ajout P9) ────────────────────────────────
    TextViewer tv(std::cout);
 
    // ── Boucle de simulation : 100 pas de temps dt = 0.001 s ─────────────────
    for (int i(0); i <= 100; ++i) {
        std::cout << "t = " << i * Constantes::dt << " s" << std::endl;
 
        // Affichage de l'état courant via le TextViewer (dessine_sur → operator<<)
        s.dessine_sur(tv);          // ← remplace : std::cout << s << std::endl;
        std::cout << std::endl;
 
        // Évolution d'un pas (algo 2 déterministe avec sauvegarde)
        s.evolue();
    }
 
    return 0;
}