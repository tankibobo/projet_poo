#include "Systeme/Systeme.h"
#include "Particule/Particule.h"
#include "Obstacle/Obstacle.h"
#include "Plan/Plan.h"
#include "Constantes.h"
#include "ParticuleNeige/ParticuleNeige.h"
#include "ParticuleRoche/ParticuleRoche.h"
#include <iostream>


int main() {
    ParticuleNeige* p1 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleRoche* p2 = new ParticuleRoche(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {1.0, 0, 0});
    ParticuleRoche* p3 = new ParticuleRoche(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.5, 0.886, 0});
    ParticuleNeige* p4 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.5, 0.288, 0.816});
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
