// SIMULATION D'EVOLUTION, DEBUT SEMAINE 6
// fonctionne avec qq erreurs notam. approximation de double (donc c normal) et cmake verifié
#include "Systeme/Systeme.h"
#include <cmath>
#include "Particule/Particule.h"
#include <iostream>

int main() {
    ParticuleNeige* p1 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleRoche* p2 = new ParticuleRoche(1.0, 0, 0, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleRoche* p3 = new ParticuleRoche(0.5, 0.886, 0, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleNeige* p4 = new ParticuleNeige(0.5, 0.288, 0.816, 1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
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