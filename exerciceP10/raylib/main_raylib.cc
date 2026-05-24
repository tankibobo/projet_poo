#include "raylib_render.h"
#include "../general/Systeme/Systeme.h"
#include "../general/Particule/Particule.h"
#include "../general/Plan/Plan.h"
#include "../general/Constantes.h"
#include <cmath>

int main() {
    Particule* p1 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    Particule* p2 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {1.0, 0.0, 0.0});
    Particule* p3 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.5, sqrt(3.0)/2.0, 0.0});
    Particule* p4 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.5, sqrt(3.0)/6.0, sqrt(6.0)/3.0});
    Plan* o1 = new Plan(0.0, 0.0, -0.9, 0.0, 0.0, 1.0);

    Systeme systeme({p1, p2, p3, p4}, {o1}, {});

    raylibRender render;
    render.run(systeme);

    return 0;
}
