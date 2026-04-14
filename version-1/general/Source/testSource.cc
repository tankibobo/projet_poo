// fonctionne et cmake verifié
#include <iostream>
#include "Source.h"
#include "../Aleatoire/Aleatoire.h"
using namespace std;

int main() {
    Aleatoire gen(1234);
    Particule modele(0,0,0, 0,0,0, 1000, 0.1, 1.8e-5, 1.3);
    Source source(modele, 0, 0, 0, 0.5, 0.01, 10.0, true, gen);

    vector<Particule*> particules;
    source.creation(particules, 0.1);

    cout << "Nombre de particules créées : " << particules.size() << endl;
    for (auto* p : particules) {
        cout << *p;
        delete p;
    }
    return 0;
}
