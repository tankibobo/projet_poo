// AVANT DE COMMECNER: TAPER git.pull, , une fois fini taper git.push
#include <iostream>
#include "Vecteur3D.h"
using namespace std;

int main() {

    // === Constructeurs ===
    Vecteur3D vect1(1.0, 2.0, -0.1);
    Vecteur3D vect2(2.6, 3.5, 4.1);
    Vecteur3D vect3(vect1);   // copie de vect1
    Vecteur3D vect4;          // vecteur nul

    cout << "Vecteur 1 : " << vect1 << endl;
    cout << "Vecteur 2 : " << vect2 << endl;
    cout << "Vecteur 3 : " << vect3 << endl;
    cout << "Vecteur 4 : " << vect4 << endl;

    // === Égalité ===
    cout << "Le vecteur 1 est ";
    if (vect1 == vect2) cout << "égal au";
    else                cout << "différent du";
    cout << " vecteur 2," << endl << "et est ";
    if (vect1 == vect3) cout << "égal au";
    else                cout << "différent du";
    cout << " vecteur 3." << endl;

    // === Addition ===
    cout << "(" << vect1 << ") + (" << vect2 << ") = (" << (vect1 + vect2) << ")" << endl;
    cout << "(" << vect2 << ") + (" << vect1 << ") = (" << (vect2 + vect1) << ")" << endl;
    cout << "(" << vect1 << ") + (" << vect4 << ") = (" << (vect1 + vect4) << ")" << endl;
    cout << "(" << vect4 << ") + (" << vect1 << ") = (" << (vect4 + vect1) << ")" << endl;

    // === Soustraction ===
    cout << "(" << vect1 << ") - (" << vect2 << ") = (" << (vect1 - vect2) << ")" << endl;
    cout << "(" << vect2 << ") - (" << vect2 << ") = (" << (vect2 - vect2) << ")" << endl;

    // === Opposé ===
    cout << "-(" << vect1 << ") = (" << (-vect1) << ")" << endl;
    cout << "-(" << vect2 << ") + (" << vect1 << ") = (" << (-vect2 + vect1) << ")" << endl;

    // === Multiplication scalaire ===
    cout << "3 * (" << vect1 << ") = (" << (3.0 * vect1) << ")" << endl;

    // === Produit scalaire ===
    cout << "(" << vect1 << ") * (" << vect2 << ") = " << (vect1 | vect2) << endl;
    cout << "(" << vect2 << ") * (" << vect1 << ") = " << (vect2 | vect1) << endl;

    // === Produit vectoriel ===
    cout << "(" << vect1 << ") ^ (" << vect2 << ") = (" << (vect1 ^ vect2) << ")" << endl;

    // === Norme et norme² ===
    cout << "||(" << vect1 << ")||^2 = " << vect1.norme2() << endl;
    cout << "||(" << vect1 << ")|| = "   << vect1.norme()  << endl;
    cout << "||(" << vect2 << ")||^2 = " << vect2.norme2() << endl;
    cout << "||(" << vect2 << ")|| = "   << vect2.norme()  << endl;

    // === Vecteur unitaire ===
    Vecteur3D direction(~vect1);
    cout << "unitaire(" << vect1 << ") = (" << direction << ")" << endl;
    cout << "||unitaire||^2 = " << direction.norme2() << " (doit être 1)" << endl;

    // === Opérateurs d'assignation +=, -= ===
    Vecteur3D v = vect1;
    v += vect2;
    cout << "vect1 += vect2 → (" << v << ")" << endl;
    v = vect1;
    v -= vect2;
    cout << "vect1 -= vect2 → (" << v << ")" << endl;

    return 0;
}
