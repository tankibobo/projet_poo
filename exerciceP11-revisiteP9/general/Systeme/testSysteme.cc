// fonctionne et cmake verifié
#include "Systeme/Systeme.h"
#include "../Particule/Particule.h"
#include "../ParticuleNeige/ParticuleNeige.h"
#include "Plan/Plan.h"
#include "Constantes.h"
#include <cmath>
#include <iostream>


int main() {
    // tests plus poussées dans exerciceP9 + chutelibre
    Particule* p1 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau);
    Particule* p2 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau, {1.0, 0, 0});
    Particule* p3 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau, {0.5, sqrt(3)/2, 0});
    Particule* p4 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau, {0.5, sqrt(3)/6, sqrt(6)/3});
    Plan* o1 = new Plan(0, 0, -0.9, 0, 0, 1);
    Systeme s({p1, p2, p3, p4}, {o1}, {});


    std::cout << s << std::endl;
    return 0;
}
