// testGrille.cc
#include "Grille.h"
#include "Particule/Particule.h"
#include "Constantes.h"
#include "../../ParticuleNeige/ParticuleNeige.h"
#include "../../ParticuleRoche/ParticuleRoche.h"
#include <iostream>


int main() {

    // instanciation
    Particule* p1 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {0.0, 0.0, 0.0});
    Particule* p2 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {2.0, 0.0, 0.0});
    Particule* p3 = new ParticuleRoche(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {4.0, 0.0, 0.0});

    Grille g({p1, p2, p3});

    //voisins
    std::vector<Particule*> voisins_p1 = g.getVoisins(p1);
    std::vector<Particule*> voisins_p2 = g.getVoisins(p2);
    std::vector<Particule*> voisins_p3 = g.getVoisins(p3);
    std::cout << "Voisins de p1  (1): " << voisins_p1.size() << std::endl;
    std::cout << "Voisins de p2 (2): " << voisins_p2.size() << std::endl;;
    std::cout << "Voisins de p3 (1): " << voisins_p3.size() << std::endl;;

    //ajt
    Particule* p4 = new ParticuleNeige(1.0, 0.4, Constantes::viscosite_air, Constantes::mv_air, {6.0, 0.0, 0.0});
    g.ajouterParticule(p4);
    auto it = g.getGrille().find({3,0,0});
    std::cout << (it->second[0] == p4) << std::endl;

    // retirer
    g.retirerParticule(p4);
    auto it2 = g.getGrille().find({3,0,0});
    std::cout << (it2 != g.getGrille().end()) << std::endl;

    //maj et agrandissement 
    std::cout << "case de p1 (before deplacement)" << p1->getX() << "," << p1->getY() << "," << p1->getZ() << std::endl;
    std::cout << "tailles before deplacemnet (x,y,z)" << g.getGrille().size() << std::endl;
    p1->setPosition({5.0, 5.0, 5.0});
    g.mettreAJour(p1);
    std::cout << "case de p1 (after deplacement)" << p1->getX() << "," << p1->getY() << "," << p1->getZ() << std::endl;
    std::cout << "tailles before deplacemnet (x,y,z)" << g.getGrille().size() << std::endl;
}
