// SIMULATION D'EVOLUTION GRAPHIQUE, FIN SEMAINE 6
// fonctionne et cmake verifié
#include "Systeme/Systeme.h"
#include "../texte/TextViewer.h"
#include "Particule/Particule.h"
#include "Obstacle/Obstacle.h"
#include "Plan/Plan.h"
#include "Constantes.h"
#include "ParticuleNeige/ParticuleNeige.h"
#include "ParticuleRoche/ParticuleRoche.h"
#include <iostream>
 
int main() {
    ParticuleNeige* p1 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleRoche* p2 = new ParticuleRoche(100, 0.4, Constantes::viscosite_air, Constantes::mv_air, {2.0, 0, 0});
    ParticuleRoche* p3 = new ParticuleRoche(100, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0, 0.886, 0});
    ParticuleNeige* p4 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.5, 0.288, 0.816});
 
    Plan* o1 = new Plan(0.0, 0.0, -0.9, 0.0, 0.0, 1.0);
 
    Systeme s({p1, p2, p3, p4}, {o1}, {});
 
    TextViewer tv(std::cout);
 
    for (int i(0); i <= 100; ++i) {
        std::cout << "t = " << i * Constantes::dt << " s" << std::endl;
 
        s.dessine_sur(tv);       
        std::cout << std::endl;
 
        s.evolue();
    }
 
    return 0;
}