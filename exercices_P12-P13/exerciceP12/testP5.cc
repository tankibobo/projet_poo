// TEST FIN SEMAINE 6
// fonctionne et cmake verifié
#include "../Systeme/Systeme.h"
#include "../Particule/Particule.h"
#include "../ParticuleNeige/ParticuleNeige.h"
#include "Constantes.h"
#include "../texte/TextViewer.h"
#include <iostream>
 
int main() {
    Particule* p1 = new ParticuleNeige(1.0,  0.4,  Constantes::viscosite_air, Constantes::mv_air);
    Particule* p2 = new ParticuleNeige(12.5, 0.15, Constantes::viscosite_air, Constantes::mv_air,{1.0, 0.0, 0.0}, {0.0, 0.2, 0.0});
    Particule* p3 = new ParticuleNeige(12.5, 0.1,  Constantes::viscosite_air, Constantes::mv_air,{0.0, 0.0, 1.0}, {0.0, 0.0, -0.05});
 
    Systeme s({p1, p2, p3}, {}, {}, true);
 
    TextViewer tv(std::cout);
 
    std::cout << "=== État initial ===" << std::endl;
    s.dessine_sur(tv);
    std::cout << std::endl;
    for (int i = 1; i <= 3; ++i) {
        s.evolue();
        std::cout << "=== Après " << i << " pas (t = "<< i * Constantes::dt << " s) ===" << std::endl;
        s.dessine_sur(tv);
        std::cout << std::endl;
    }
 

    return 0;
}
