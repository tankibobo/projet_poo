// SIMULATION D'EVOLUTION, DEBUT SEMAINE 6
// fonctionne avec qq erreurs notam. approximation de double (donc c normal) et cmake verifié
#include "../../Systeme/Systeme.h"
#include <cmath>
#include <iostream>

int main() {
    Particule* p1 = new Particule(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    Particule* p2 = new Particule(1.0, 0, 0, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    Particule* p3 = new Particule(0.5, sqrt(3)/2, 0, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    Particule* p4 = new Particule(0.5, sqrt(3)/6, sqrt(6)/3, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    Plan* o1 = new Plan(0, 0, -0.9, 0, 0, 1);
    Systeme s({p1, p2, p3, p4}, {o1}, {});

    for(int i(0); i <= 100; i++) {
        std::cout << "t:" << i * Constantes::dt << std::endl;
        std::cout << std::endl;

        std::cout << s << std::endl;
        s.evolue();
    }
    return 0;
}