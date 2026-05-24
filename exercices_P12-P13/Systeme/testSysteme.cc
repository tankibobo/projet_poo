// fonctionne et cmake verifié
#include "Systeme.h"
#include <cmath>
#include <iostream>
#include "Constantes.h"
#include "../Particule/Particule.h"

int main() {
    Particule* p1 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau);
    Particule* p2 = new Particule(1.0, 0, 0, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau);
    Particule* p3 = new Particule(0.5, sqrt(3)/2, 0, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau);
    Particule* p4 = new Particule(0.5, sqrt(3)/6, sqrt(6)/3, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau);
    Plan* o1 = new Plan(0, 0, -0.9, 0, 0, 1);
    Systeme s({p1, p2, p3, p4}, {o1}, {});

    std::cout << s << std::endl;
    return 0;
}