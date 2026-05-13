// fonctionne et cmake verifié
#include "Systeme.h"
#include <cmath>
#include <iostream>

int main() {
    ParticuleNeige* p1 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau);
    ParticuleNeige* p2 = new ParticuleNeige(1.0, 0, 0, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau);
    ParticuleNeige* p3 = new ParticuleNeige(0.5, sqrt(3)/2, 0, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau);
    ParticuleNeige* p4 = new ParticuleNeige(0.5, sqrt(3)/6, sqrt(6)/3, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_eau);
    Plan* o1 = new Plan(0, 0, -0.9, 0, 0, 1);
    Systeme s({p1, p2, p3, p4}, {o1}, {});

    std::cout << s << std::endl;
    return 0;
}