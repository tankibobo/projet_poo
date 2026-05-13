// TEST FIN SEMAINE 6
// fonctionne et cmake verifié
#include "Systeme/Systeme.h"
#include "../texte/TextViewer.h"
#include <iostream>
 
int main() {

    ParticuleNeige* p1 = new ParticuleNeige(0.0, 0.0, 0.0,  0.0, 0.0,   0.0,1.0,  0.4,  Constantes::viscosite_air, Constantes::mv_air);
    ParticuleNeige* p2 = new ParticuleNeige(1.0, 0.0, 0.0,  0.0, 0.2,   0.0,12.5, 0.15, Constantes::viscosite_air, Constantes::mv_air);
    ParticuleNeige* p3 = new ParticuleNeige(0.0, 0.0, 1.0,  0.0, 0.0,  -0.05,12.5, 0.1,  Constantes::viscosite_air, Constantes::mv_air);
 

    Systeme s({p1, p2, p3}, {}, {});
 
    TextViewer tv(std::cout);
 
    std::cout << "etat initial" << std::endl;
    s.dessine_sur(tv);
    std::cout << std::endl;


    for (int i = 1; i <= 3; ++i) {
        s.evolue();
        std::cout << "n" <<i << ", t = "<< i * Constantes::dt << "s" << std::endl;
        s.dessine_sur(tv);
        std::cout << std::endl;
    }
 
    return 0;
}
