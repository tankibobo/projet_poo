// fonctionne et cmake verifié
#include <iostream>
#include "Vecteur3D.h"


int main() {


    //test des constructeurs
    Vecteur3D vect1(1.0, 2.0, -0.1);
    Vecteur3D vect2(2.6, 3.5, 4.1);
    Vecteur3D vect3(vect1);
    Vecteur3D vect4;


    std::cout << "Vecteur 1 : " << vect1 << std::endl;
    std::cout << "Vecteur 2 : " << vect2 << std::endl;
    std::cout << "Vecteur 3 : " << vect3 << std::endl;
    std::cout << "Vecteur 4 : " << vect4 << std::endl;


    //test des bool d'egalite
    std::cout << "Le vecteur 1 est ";
    if (vect1 == vect2) std::cout << "égal au";
    else std::cout << "différent du";
    std::cout << " vecteur 2," << std::endl << "et est ";
    if (vect1 == vect3) std::cout << "égal au";
    else std::cout << "différent du";
    std::cout << " vecteur 3." << std::endl;


    // test des operateurs/surcharge
    std::cout << "(" << vect1 << ") + (" << vect2 << ") = (" << (vect1 + vect2) << ")" << std::endl;
    std::cout << "(" << vect2 << ") + (" << vect1 << ") = (" << (vect2 + vect1) << ")" << std::endl;
    std::cout << "(" << vect1 << ") + (" << vect4 << ") = (" << (vect1 + vect4) << ")" << std::endl;
    std::cout << "(" << vect4 << ") + (" << vect1 << ") = (" << (vect4 + vect1) << ")" << std::endl;


    std::cout << "(" << vect1 << ") - (" << vect2 << ") = (" << (vect1 - vect2) << ")" << std::endl;
    std::cout << "(" << vect2 << ") - (" << vect2 << ") = (" << (vect2 - vect2) << ")" << std::endl;


    std::cout << "-(" << vect1 << ") = (" << (-vect1) << ")" << std::endl;
    std::cout << "-(" << vect2 << ") + (" << vect1 << ") = (" << (-vect2 + vect1) << ")" << std::endl;


    std::cout << "3 * (" << vect1 << ") = (" << (3.0 * vect1) << ")" << std::endl;


    std::cout << "(" << vect1 << ") * (" << vect2 << ") = " << (vect1 | vect2) << std::endl;
    std::cout << "(" << vect2 << ") * (" << vect1 << ") = " << (vect2 | vect1) << std::endl;


    std::cout << "(" << vect1 << ") ^ (" << vect2 << ") = (" << (vect1 ^ vect2) << ")" << std::endl;


    std::cout << "||(" << vect1 << ")||^2 = " << vect1.norme2() << std::endl;
    std::cout << "||(" << vect1 << ")|| = " << vect1.norme() << std::endl;
    std::cout << "||(" << vect2 << ")||^2 = " << vect2.norme2() << std::endl;
    std::cout << "||(" << vect2 << ")|| = " << vect2.norme() << std::endl;


    Vecteur3D direction(~vect1);
    std::cout << "unitaire(" << vect1 << ") = (" << direction << ")" << std::endl;
    std::cout << "||unitaire||^2 = " << direction.norme2() << " (doit être 1)" << std::endl;


    Vecteur3D v = vect1;
    v += vect2;
    std::cout << "vect1 += vect2 → (" << v << ")" << std::endl;
    v = vect1;
    v -= vect2;
    std::cout << "vect1 -= vect2 → (" << v << ")" << std::endl;


    return 0;
}
