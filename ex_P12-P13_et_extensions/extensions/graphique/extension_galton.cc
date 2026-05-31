#include "raylib_render.h"
#include "ParticuleNeige/ParticuleNeige.h"
#include "Brique/Brique.h"
#include "Cylindre/Cylindre.h"
#include "Source/Source.h"
#include "Aleatoire/Aleatoire.h"
#include "Constantes.h"
#include "Systeme/Systeme.h"


// Planche de Galton :
//   - Source au sommet qui émet des particules vers le bas
//   - 4 rangées de cylindres horizontaux (axe selon sim-y)
//     disposés en quinconce, comme les chevilles d'une planche de Galton
//   - Brique en bas


int main() {
    // Sol
    Brique* sol = new Brique({0.0, 2.0, -0.25}, 10.0, 6.0, 0.5, {1,0,0}, {0,1,0});

    // restitution=0.3 : rebond faible (30% de la vitesse normale est restituée)
    // avec_lj=false  : pas de force LJ — sinon les particules sont suspendues entre deux cylindres voisins à cause de la repulsion LJ
    Cylindre* c1_1 = new Cylindre({-0.8, 2.0, 8.0}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c1_2 = new Cylindre({ 0.8, 2.0, 8.0}, 0.2, 5.0, {0,1,0}, 0.3, false);

    // Rangée 2 : 3 cylindres à z=6.5
    Cylindre* c2_1 = new Cylindre({-1.6, 2.0, 6.5}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c2_2 = new Cylindre({ 0.0, 2.0, 6.5}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c2_3 = new Cylindre({ 1.6, 2.0, 6.5}, 0.2, 5.0, {0,1,0}, 0.3, false);

    // Rangée 3 : 4 cylindres à z=5.0
    Cylindre* c3_1 = new Cylindre({-2.4, 2.0, 5.0}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c3_2 = new Cylindre({-0.8, 2.0, 5.0}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c3_3 = new Cylindre({ 0.8, 2.0, 5.0}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c3_4 = new Cylindre({ 2.4, 2.0, 5.0}, 0.2, 5.0, {0,1,0}, 0.3, false);

    // Rangée 4 : 5 cylindres à z=3.5
    Cylindre* c4_1 = new Cylindre({-3.2, 2.0, 3.5}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c4_2 = new Cylindre({-1.6, 2.0, 3.5}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c4_3 = new Cylindre({ 0.0, 2.0, 3.5}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c4_4 = new Cylindre({ 1.6, 2.0, 3.5}, 0.2, 5.0, {0,1,0}, 0.3, false);
    Cylindre* c4_5 = new Cylindre({ 3.2, 2.0, 3.5}, 0.2, 5.0, {0,1,0}, 0.3, false);

    // Générateur aléatoire
    Aleatoire gen(42);

    // Modèle de particule : petite ParticuleNeige
    ParticuleNeige modele(1.0, 0.12, Constantes::viscosite_air, Constantes::mv_air, {0.0, 2.0, 9.5});

    // Source : émission au sommet avec légère dispersion horizontale
    // ecart_v=0.1  → légère variation de vitesse initiale (crée l'asymétrie nécessaire)
    // ecart_r=0.01 → rayon presque constant
    // debit=30    → ~6 particules par seconde réelle (dt=0.001, 60 fps)
    Source* source = new Source(modele, 0.0, 2.0, 9.5, 0.1, 0.01, 30.0, true, gen);

    Systeme systeme(
        {},
        {
            sol,
            c1_1, c1_2,
            c2_1, c2_2, c2_3,
            c3_1, c3_2, c3_3, c3_4,
            c4_1, c4_2, c4_3, c4_4, c4_5
        },
        {source}
    );

    raylibRender render;
    render.run(systeme);

    return 0;
}
