// TEST FIN SEMAINE 6
// fonctionne et cmake verifié
#include "Systeme/Systeme.h"
#include "../texte/TextViewer.h"
#include "Particule/Particule.h"
#include "Constantes.h"
#include <iostream>
 
int main() {
    // ── Création des particules ───────────────────────────────────────────────
    // Constructeur : Particule(x, y, z, vx, vy, vz, mv, r, visc, mv_milieu)
    Particule* p1 = new Particule(
        1.0,  0.4,  Constantes::viscosite_air, Constantes::mv_air
    );
    Particule* p2 = new Particule(
        12.5, 0.15, Constantes::viscosite_air, Constantes::mv_air,
        {1.0, 0.0, 0.0}, {0.0, 0.2, 0.0}
    );
    Particule* p3 = new Particule(
        12.5, 0.1,  Constantes::viscosite_air, Constantes::mv_air,
        {0.0, 0.0, 1.0}, {0.0, 0.0, -0.05}
    );
 
    // Pas d'obstacle ni de source pour ce test
    Systeme s({p1, p2, p3}, {}, {});
 
    TextViewer tv(std::cout);
 
    // ── État initial ──────────────────────────────────────────────────────────
    std::cout << "=== État initial ===" << std::endl;
    s.dessine_sur(tv);
    std::cout << std::endl;
 
    // ── Évolution sur 3 pas (dt = 0.001 s) ───────────────────────────────────
    // Systeme::evolue() : algorithme déterministe avec sauvegarde (algo 2) :
    //   boucle 1 — cumul des forces pour toutes les particules (positions courantes)
    //   boucle 2 — déplacement de toutes les particules
    for (int i = 1; i <= 3; ++i) {
        s.evolue();
        std::cout << "=== Après " << i << " pas (t = "
                  << i * Constantes::dt << " s) ===" << std::endl;
        s.dessine_sur(tv);
        std::cout << std::endl;
    }
 
    return 0;
}
