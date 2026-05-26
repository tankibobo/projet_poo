// fonctionne et cmake verifié
#include <iostream>
#include "Source/Source.h"
#include <vector>
#include "Aleatoire/Aleatoire.h"
#include "../Particule/Particule.h"

int main() {
    Aleatoire gen(1234);
    Particule modele(1000, 0.1, 1.8e-5, 1.3);
    Source source(modele, 0, 0, 0, 0.5, 0.01, 10.0, true, gen);

    std::vector<Particule*> particules;
    source.creation(particules, 0.1);

    std::cout << "Nombre de particules créées : " << particules.size() << std::endl;
    for (auto* p : particules) {
        std::cout << *p;
        delete p;
    }
    return 0;
}
