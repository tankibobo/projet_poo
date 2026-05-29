#include "Systeme/Systeme.h"
#include "../texte/TextViewer.h"
#include "Particule/Particule.h"
#include "Constantes.h"
#include <iostream>
 

int main() {
    // Particule : pos=(0,0,0), v=(5,0,7) mm/s, ρ=1 mg/mm³, r=0.4 mm, milieu=air
    Particule* p = new Particule(
        1.0, // ρ_grain = 1 mg/mm³ (= mv_eau)
        0.4, // rayon (mm)
        Constantes::viscosite_air, // η_milieu
        Constantes::mv_air, // ρ_milieu
        {0.0, 0.0, 0.0}, // position initiale
        {5.0, 0.0, 7.0} // vitesse initiale (mm/s)
    );
 

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
        // Algorithme déterministe sans sauvegarde (une seule particule) :
        // 1. Force perso uniquement (pas d'obstacles, pas d'autres grains)
        // 2. Déplacement Euler-Cromer
        for (Particule* part : s.getParticules()) {
            part->ajouteForce(); // poids − frottement fluide
            part->bouger(dt);
        }
        s.dessine_sur(tv);
        std::cout << std::endl;
    }
 

    return 0;
}
