#include "../../Systeme/Systeme.h"
#include "../texte/TextViewer.h"
#include "../../Particule/Particule.h"
#include "../../ParticuleNeige/ParticuleNeige.h"
#include <iostream>
 
int main() {
    Systeme s({new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air)}, {}, {}, true);
 
    TextViewer tv(std::cout);
 
    std::cout << "Le système est composé des " << s.getParticules().size() << " particule(s) suivante(s) :" << std::endl;
    s.dessine_sur(tv);
    std::cout << std::endl;
 
    for (int i = 0; i < 150; ++i) {
        s.evolue();
        s.dessine_sur(tv);
        std::cout << std::endl;
    }
    
    //on devrait avoir à peu près -1m/s à la fin 
    return 0;
}
