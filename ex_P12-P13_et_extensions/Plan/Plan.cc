#include "Plan.h"
#include <ostream>
#include "Vecteur3D/Vecteur3D.h"

// ── Plan ─────────────────────────────────────────────────────────────────────

Vecteur3D Plan::PointPlusProche(Vecteur3D const& x_i) const {
    Vecteur3D x_i_p = position - x_i;
    double d = x_i_p | normale;
    return x_i + d*normale;
}

std::ostream& Plan::affiche(std::ostream& os) const {
    os << "Plan d'origine: " << getPos() << " et de normale: (" << getNormale() << ")";
    return os;
}

// ── Dalle ────────────────────────────────────────────────────────────────────

Vecteur3D Dalle::PointPlusProche(Vecteur3D const& x_i) const {
    //On a dû changer le calcul car Dalle n'est pas infini, reprise de quelques parties du code de Brique.
    Vecteur3D proj = Plan::PointPlusProche(x_i);

    Vecteur3D local = proj - position;
    double coord_l = local | direction_longueur;
    double coord_L = local | direction_largeur;

    if (coord_l < -longueur / 2.0) coord_l = -longueur / 2.0;
    if (coord_l >  longueur / 2.0) coord_l =  longueur / 2.0;
    if (coord_L < -largeur  / 2.0) coord_L = -largeur  / 2.0;
    if (coord_L >  largeur  / 2.0) coord_L =  largeur  / 2.0;

    return position + coord_l * direction_longueur + coord_L * direction_largeur;
}

std::ostream& Dalle::affiche(std::ostream& os) const {
    os << "Dalle d'origine: " << getPos()
       << ", normale: "   << getNormale()
       << ", longueur: "  << longueur
       << ", largeur: "   << largeur;
    return os;
}