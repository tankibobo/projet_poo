#include "Grille.h"
#include "../../../Particule/Particule.h"
#include <vector>
#include <iostream>

int main() {
    Particule* p1 = new Particule(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.5, 1.0, 1.0); //vérifie en même temps "agrandirGrille" puisque la grille n'a pas de taille a la base
    Particule* p2 = new Particule(0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 0.5, 1.0, 1.0);
    Particule* p3 = new Particule(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.5, 1.0, 1.0);
    Grille g({p1, p2, p3});
    std::vector<Particule*> voisins_p1 = g.getVoisins(p1);
    std::cout << "Voisins de p1 : " << voisins_p1.size() << std::endl;
    std::cout << "Position de p1 : " << p1->get_position() << ", Grille: (" << p1->getX() << ", " << p1->getY() << ", " << p1->getZ() << ")" << std::endl;
    std::cout << "Position de p2 : " << p2->get_position() << ", Grille: (" << p2->getX() << ", " << p2->getY() << ", " << p2->getZ() << ")" << std::endl;
    p1->ajouteForce(*p2);
    p1->bouger(0.1);
    g.mettreAJour(p1);
    std::cout << "Position de p1 après déplacement : " << p1->get_position() << ", Grille: (" << p1->getX() << ", " << p1->getY() << ", " << p1->getZ() << ")" << std::endl;
    delete p1;
    delete p2;
    delete p3;
    return 0;
}