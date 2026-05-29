#include "../../Systeme/Systeme.h"
#include "../texte/TextViewer.h"
#include <iostream>
#include "../../Particule/Particule.h"
 

int main() {
    // Particule : pos=(0,0,0), v=(5,0,7) mm/s, ρ=1 mg/mm³, r=0.4 mm, milieu=air
    Particule* p = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0,0,0},{5.0, 0.0, 7.0});
 

    Systeme s;
    s.ajoute_particule(p);
 

    TextViewer tv(std::cout);
 

    // ── État initial ──────────────────────────────────────────────────────────
    std::cout << "Le système est composé des "
              << s.getParticules().size() << " particule(s) suivante(s) :" << std::endl;
    s.dessine_sur(tv);
    std::cout << std::endl;
 

    // ── Évolution : pas de temps dt = 0.01 s ─────────────────────────────────
    constexpr double dt = 0.01; // pas physique voulu (trajectoire quasi-parabolique)
 

    for (int i = 0; i < 15; ++i) {
        for (Particule* part : s.getParticules()) {
            part->ajouteForce(); // poids − frottement fluide
            part->bouger(dt);
        }
        s.dessine_sur(tv);
        std::cout << std::endl;
    }
 

    return 0;
}
