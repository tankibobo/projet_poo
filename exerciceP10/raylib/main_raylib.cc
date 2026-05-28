#include "raylib_render.h"
#include "Plan/Plan.h"
#include "Source/Source.h"
#include "Aleatoire/Aleatoire.h"
#include "Constantes.h"
#include <cmath>

int main() {
    // Plan horizontal à z = -0.5 (bien visible sous les particules)
    Plan* o1 = new Plan(0.0, 0.0, -0.5, 0.0, 0.0, 1.0);

    // 4 particules initiales en tétraèdre, en hauteur (z=3) pour voir la chute
    Particule* p1 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.0, 0.0, 3.0});
    Particule* p2 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {1.0, 0.0, 3.0});
    Particule* p3 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.5, sqrt(3.0)/2.0, 3.0});
    Particule* p4 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.5, sqrt(3.0)/6.0, 3.0 + sqrt(6.0)/3.0});

    // On a ajouté une source pour que ce soit plus joli et compréhensible
    Aleatoire gen(42);
    Particule modele(1.0, 0.3, Constantes::viscosite_air, Constantes::mv_air, {0.0, 0.0, 6.0});
    Source* s1 = new Source(modele, 0.0, 0.0, 6.0,
                             /*ecart_v=*/0.2, /*ecart_r=*/0.05,
                             /*debit=*/17.0,  /*etat=*/true, gen);

    Systeme systeme({p1, p2, p3, p4}, {o1}, {s1});

    raylibRender render;
    render.run(systeme);

    return 0;
}
