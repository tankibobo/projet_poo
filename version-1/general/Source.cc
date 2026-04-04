#include "Source.h"
#include "Aleatoire.h"
#include "Vecteur3D.h"

void Source::creation(std::vector<Particule*>& particules, double dt) {
    if (!etat) return;

    double fraction(debit * dt);
    int nombre(fraction);
    fraction -= nombre;
    if (generateur.uniforme(0.0, 1.0) < fraction) ++nombre;

    for (int i(0); i < nombre; ++i) {
        Particule* p = new Particule(modele);

        Vecteur3D v(
            generateur.gaussienne(vitesse_moyenne.getX(), ecart_type_vitesse),
            generateur.gaussienne(vitesse_moyenne.getY(), ecart_type_vitesse),
            generateur.gaussienne(vitesse_moyenne.getZ(), ecart_type_vitesse)
        );
        p->setVitesse(v);

        // Étape 4 : rayon aléatoire gaussien
        double rayon = generateur.gaussienne(modele.getRayon(), ecart_type_rayon);
        p->setRayon(rayon);

        particules.push_back(p);
    }
}

std::ostream& operator<<(std::ostream& os, const Source& s) {
    os << "Pos: " << s.getPosition() << ", Debit: " << s.getDebit() << ", Etat: " << (s.getEtat() ? "On" : "Off") << ", Vitesse Moyenne: " << s.getVitesseMoyenne() << ", Ecart Type Vitesse: " << s.getEcartTypeVitesse() << ", Ecart Type Rayon: " << s.getEcartTypeRayon();
    return os;
}