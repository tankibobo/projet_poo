#include "Aleatoire/Aleatoire.h"
#include "Vecteur3D/Vecteur3D.h"
#include "Source/Source.h"
#include "../Particule/Particule.h"
#include <iostream>
#include <vector>


void Source::creation(std::vector<Particule*>& particules, double dt) {
    if (!etat) return;


    double fraction(debit * dt);
    //static_cast pour éviter les warnings de conversion double->int
    int nombre(static_cast<int>(fraction));
    fraction -= nombre;
    if (generateur.uniforme(0.0, 1.0) < fraction) ++nombre;


    for (int i(0); i < nombre; ++i) {
        Particule* p = modele.copie(); // evite d'appeller le cc sur une classe abstraite


        Vecteur3D v(
            generateur.gaussienne(vitesse_moyenne.getX(), ecart_type_vitesse),
            generateur.gaussienne(vitesse_moyenne.getY(), ecart_type_vitesse),
            generateur.gaussienne(vitesse_moyenne.getZ(), ecart_type_vitesse)
        );
        p->setVitesse(v);


        double rayon = generateur.gaussienne(modele.getRayon(), ecart_type_rayon);
        p->setRayon(rayon);


        particules.push_back(p);
    }
}


std::ostream& operator<<(std::ostream& os, const Source& s) {
    os << "Pos: " << s.getPosition() << ", Debit: " << s.getDebit() << ", Etat: " << (s.getEtat() ? "On" : "Off") << ", Vitesse Moyenne: " << s.getVitesseMoyenne() << ", Ecart Type Vitesse: " << s.getEcartTypeVitesse() << ", Ecart Type Rayon: " << s.getEcartTypeRayon();
    return os;
}
