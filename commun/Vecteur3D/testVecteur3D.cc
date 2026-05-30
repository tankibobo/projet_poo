// fonctionne et cmake verifié
#include <iostream>
#include "Vecteur3D.h"


int main() {
    // la manière dont fonctionne ce fichier test: s'il y a une absurdité mathématique dans l'execution (dans les affichages), alors y'a une erreur

    // constructeurs )
    Vecteur3D vect1(1.0, 2.0, -0.1);
    Vecteur3D vect2(2.6, 3.5, 4.1);
    Vecteur3D vect3(vect1); //copie
    Vecteur3D vect4;//défaut

    // operateur d'affichage
    std::cout << "Vecteur 1 : " << vect1 << std::endl; 
    std::cout << "Vecteur 2 : " << vect2 << std::endl;
    std::cout << "Vecteur 3 : " << vect3 << std::endl;
    std::cout << "Vecteur 4 : " << vect4 << std::endl;


    //operateur d'égalité
    if (vect1 == vect2) {std::cout << "v1 = v2" << std::endl;} else {std::cout << "v1 != v2"<< std::endl;}
    if (vect1 == vect3) {std::cout << "v1 = v3" << std::endl;} else {std::cout << "v1 != v3" << std::endl;}

    // surcharges d'operateurs
    // +, *
    std::cout << vect1 << "+" << vect2 << " = " << (vect1 + vect2) << std::endl;
    std::cout << vect1 << "+" << vect2 << " = " << (vect2 + vect1) << std::endl;
    std::cout << vect3 << "+" << vect1 << " = " << (2*vect1) << " = " << (2*vect3) << std::endl;

    //-
    std::cout << vect1 << "-" << vect2 << " = " << (vect1 - vect2) << std::endl;

    //-v
    std::cout << "-" << vect1 << " = " << (-vect1) << std::endl;

    // |
    std::cout << vect1 << " * (ou |) " << vect2 << " = " << (vect1 | vect2) << std::endl;
    std::cout << vect2 << " * (|) " << vect1 << " = " << (vect2 | vect1) << std::endl;

    // ^
    std::cout << vect2 << " ^ " << vect1 << " = " << (vect2 ^ vect1) << std::endl;

    //norme
    std::cout << "||" << vect2 << "||^2 = " << vect2.norme2() << " = " << vect2.norme()*vect2.norme() << std::endl;
    std::cout << "||" << vect2 << "|| = "   << vect2.norme()  << std::endl;

    // ~
    std::cout << "unitaire de " << vect1 << " = " << (~vect1) << std::endl;
    std::cout << 1 << " = " << (~vect1).norme() << std::endl;

    // surcharge interne
    Vecteur3D v = vect1;
    v += vect2;
    std::cout << vect1 << " + " << vect2 << " = " << v << std::endl;
    v = vect1;
    v -= vect2;
    std::cout << "vect1 - vect2 = " << v << std::endl;

    // cas limites
    Vecteur3D v1(1e-11, 0, 0);
    std::cout << v1 << " est nul? " << (v1 == Vecteur3D(0, 0, 0)) << std::endl;
    v1.def_coord(0, 0, 0);
    std::cout << "l'unitaire de v1 = (0,0,0) est nul, " << (~v1) << std::endl;

    // set coor
    std::cout << vect3 << std::endl;
    vect3.set_coord(1, 4);
    std::cout << "on change la coordonnée 1 de ce vecteur à 4, " << vect3 << std::endl;
    return 0;
}
