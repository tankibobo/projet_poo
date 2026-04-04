#include "Systeme.h"
#include <cmath>
#include <iostream>

int main() {
    Particule* p1 = new Particule(Constantes::mv_eau, 0.4, Constantes::viscosite_eau, 1);
    Particule* p2 = new Particule(1, 0, 0, Constantes::mv_eau, 0.4, Constantes::viscosite_eau, 1);
    Particule* p3 = new Particule(0.5, sqrt(3)/2, 0, Constantes::mv_eau, 0.4, Constantes::viscosite_eau, 1);
    Particule* p4 = new Particule(0.5, sqrt(3)/6, sqrt(6)/3, Constantes::mv_eau, 0.4, Constantes::viscosite_eau, 1);
    Plan* o1 = new Plan(0, 0, -0.9, 0, 0, 1);
    Systeme s({p1, p2, p3, p4}, {o1}, {});

    std::cout << s << std::endl;
    return 0;
}