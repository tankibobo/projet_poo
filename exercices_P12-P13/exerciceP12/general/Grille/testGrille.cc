#include "Grille.h"
#include "Particule/Particule.h"
#include <iostream>
#include <vector>


// sigma = 0.885, taille_case = 2*0.885 = 1.77


void check(bool condition, const std::string& message) {
    if (condition) std::cout << "[OK] " << message << std::endl;
    else std::cout << "[FAIL] " << message << std::endl;
}


int main() {


    // ===== TEST 1 : Construction simple, positions positives =====
    // p1 en (0.5, 0.5, 0.5) → case (0,0,0)
    // p2 en (4.04, 0.5, 0.5) → case (2,0,0)
    {
        Particule* p1 = new Particule(1.0, 1.0, 1.0, 1.0, {0.5, 0.5, 0.5});
        Particule* p2 = new Particule(1.0, 1.0, 1.0, 1.0, {4.04, 0.5, 0.5});
        Grille g({p1, p2});


        std::cout << "Test1: p1.x=" << p1->getX() << " p2.x=" << p2->getX() << std::endl;
        check(p1->getX() == 0, "Test1: p1.x == 0");
        check(p2->getX() == 2, "Test1: p2.x == 2");
        check(g.getParticules().size() == 2, "Test1: 2 particules dans la grille");


        delete p1; delete p2;
    }


    // ===== TEST 2 : Construction avec positions négatives =====
    // p1 en (-3.04, 0.5, 0.5) → case -2 → après décalage x=0
    // p2 en (2.27, 0.5, 0.5) → case 1 → après décalage x=3
    {
        Particule* p1 = new Particule(1.0, 1.0, 1.0, 1.0, {-3.04, 0.5, 0.5});
        Particule* p2 = new Particule(1.0, 1.0, 1.0, 1.0, { 2.27, 0.5, 0.5});
        Grille g({p1, p2});


        std::cout << "Test2: p1.x=" << p1->getX() << " p2.x=" << p2->getX() << std::endl;
        check(p1->getX() == 0, "Test2: p1.x == 0 (apres decalage)");
        check(p2->getX() == 3, "Test2: p2.x == 3 (apres decalage)");
        check(g.getParticules().size() == 2, "Test2: 2 particules dans la grille");


        delete p1; delete p2;
    }


    // ===== TEST 3 : ajouterParticule dans une case existante =====
    // p1 et p2 toutes les deux dans case (0,0,0)
    {
        Particule* p1 = new Particule(1.0, 1.0, 1.0, 1.0, {0.3, 0.3, 0.3});
        Particule* p2 = new Particule(1.0, 1.0, 1.0, 1.0, {0.5, 0.5, 0.5});
        Grille g({p1});
        g.ajouterParticule(p2);


        std::cout << "Test3: p2.x=" << p2->getX() << std::endl;
        check(p2->getX() == 0, "Test3: p2 dans case (0,0,0)");
        check(g.getParticules().size() == 2, "Test3: 2 particules dans la grille");


        delete p1; delete p2;
    }


    // ===== TEST 4 : ajouterParticule hors grille → agrandirGrille =====
    // grille initiale 1x1x1, p2 en case (5,0,0)
    {
        Particule* p1 = new Particule(1.0, 1.0, 1.0, 1.0, {0.5, 0.5, 0.5});
        Particule* p2 = new Particule(1.0, 1.0, 1.0, 1.0, {9.35, 0.5, 0.5});
        Grille g({p1});
        g.ajouterParticule(p2);


        std::cout << "Test4: p2.x=" << p2->getX() << std::endl;
        check(p2->getX() == 5, "Test4: p2.x == 5 apres agrandissement");
        check(g.getParticules().size() == 2, "Test4: 2 particules apres agrandissement");


        delete p1; delete p2;
    }


    // ===== TEST 5 : retirerParticule =====
    {
        Particule* p1 = new Particule(1.0, 1.0, 1.0, 1.0, {0.5, 0.5, 0.5});
        Particule* p2 = new Particule(1.0, 1.0, 1.0, 1.0, {2.27, 0.5, 0.5});
        Grille g({p1, p2});
        g.retirerParticule(p1);


        std::cout << "Test5: nb=" << g.getParticules().size() << std::endl;
        check(g.getParticules().size() == 1, "Test5: 1 particule apres retrait");
        check(g.getParticules()[0] == p2, "Test5: p2 toujours presente");


        delete p1; delete p2;
    }


    // ===== TEST 6 : getVoisins =====
    // p1 case 0, p2 case 1 (voisins), p3 case 5 (pas voisin)
    {
        Particule* p1 = new Particule(1.0, 1.0, 1.0, 1.0, {0.5, 0.5, 0.5});
        Particule* p2 = new Particule(1.0, 1.0, 1.0, 1.0, {2.27, 0.5, 0.5});
        Particule* p3 = new Particule(1.0, 1.0, 1.0, 1.0, {9.35, 0.5, 0.5});
        Grille g({p1, p2, p3});


        std::cout << "Test6: p1.x=" << p1->getX() << " p2.x=" << p2->getX() << " p3.x=" << p3->getX() << std::endl;
        std::vector<Particule*> voisins = g.getVoisins(p1);
        std::cout << "Test6: nb voisins=" << voisins.size() << std::endl;
        check(voisins.size() == 1, "Test6: p1 a 1 voisin");
        check(voisins.size() >= 1 && voisins[0] == p2, "Test6: voisin de p1 est p2");


        delete p1; delete p2; delete p3;
    }


    // ===== TEST 7 : mettreAJour =====
    // p1 déplacée de case 0 vers case 2
    {
        Particule* p1 = new Particule(1.0, 1.0, 1.0, 1.0, {0.5, 0.5, 0.5});
        Grille g({p1});


        check(p1->getX() == 0, "Test7: avant update, p1.x == 0");
        p1->setPosition({4.04, 0.5, 0.5});
        g.mettreAJour(p1);


        std::cout << "Test7: p1.x apres=" << p1->getX() << std::endl;
        check(p1->getX() == 2, "Test7: apres update, p1.x == 2");
        check(g.getParticules().size() == 1, "Test7: toujours 1 particule");


        delete p1;
    }


    // ===== TEST 8 : ajouterParticule position négative après construction =====
    // p1 case 1, p2 case -1 → après décalage p1=2, p2=0
    {
        Particule* p1 = new Particule(1.0, 1.0, 1.0, 1.0, { 2.27, 0.5, 0.5});
        Particule* p2 = new Particule(1.0, 1.0, 1.0, 1.0, {-1.27, 0.5, 0.5});
        Grille g({p1});
        g.ajouterParticule(p2);


        std::cout << "Test8: p1.x=" << p1->getX() << " p2.x=" << p2->getX() << std::endl;
        check(g.getParticules().size() == 2, "Test8: 2 particules apres ajout negatif");
        check(p2->getX() == 0, "Test8: p2 repositionnee en x=0");
        check(p1->getX() == 2, "Test8: p1 decalee en x=2");


        delete p1; delete p2;
    }


    return 0;
}
