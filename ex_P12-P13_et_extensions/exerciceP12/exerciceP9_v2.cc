// SIMULATION D'EVOLUTION GRAPHIQUE, FIN SEMAINE 6
// fonctionne et cmake verifié
#include "../texte/TextViewer.h" 
#include "../Systeme/Systeme.h"
#include "../Particule/Particule.h"
#include "../ParticuleNeige/ParticuleNeige.h"
#include "../ParticuleRoche/ParticuleRoche.h"
#include "../Plan/Plan.h"
#include "../Obstacle/Obstacle.h"
#include "Constantes.h"
#include <cmath>
#include <iostream>
 
int main() {
    Particule* p1 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air);
    Particule* p2 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {1.0, 0.0, 0.0});
    Particule* p3 = new ParticuleRoche(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.5, sqrt(3.0)/2.0, 0.0});
    Particule* p4 = new ParticuleRoche(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.5, sqrt(3.0)/6.0, sqrt(6.0)/3.0});  // pos = (1/2, √3/6, √6/3)
 
    Plan* o1 = new Plan(0.0, 0.0, -0.9, 0.0, 0.0, 1.0);
 
    Systeme s({p1, p2, p3, p4}, {o1}, {}, true);
 
    TextViewer tv(std::cout);
 

    for (int i(0); i <= 100; ++i) {
        std::cout << "t = " << i * Constantes::dt << " s" << std::endl;
 

        s.dessine_sur(tv);
        std::cout << std::endl;
 

        s.evolue();
    }
 

    return 0;
}
