#include "Brique.h"
#include "Vecteur3D/Vecteur3D.h"
#include <ostream>


Brique::Brique(Vecteur3D const& centre_, double longueur, double largeur, double profondeur, Vecteur3D const& dir_longueur_, Vecteur3D const& dir_largeur_, double restitution_) : centre(centre_), demi_longueur(longueur/2.0), demi_largeur(largeur/2.0), demi_profondeur(profondeur/2.0), dir_longueur(~dir_longueur_), dir_largeur(~dir_largeur_), dir_profondeur(~(dir_longueur_ ^ dir_largeur_)), restitution(restitution_) {
    if (restitution < 0.0 or restitution > 1.0) restitution = 1.0;
}


// Indice de la face la plus proche : 0/1=±longueur, 2/3=±largeur, 4/5=±profondeur
static int facePlusProche(double d_longueur_pos, double d_longueur_neg, double d_largeur_pos, double d_largeur_neg, double d_profondeur_pos, double d_profondeur_neg)
{
    int idx = 0;
    double dmin = d_longueur_pos;
    if (d_longueur_neg < dmin) { dmin = d_longueur_neg; idx = 1; }
    if (d_largeur_pos < dmin) { dmin = d_largeur_pos; idx = 2; }
    if (d_largeur_neg < dmin) { dmin = d_largeur_neg; idx = 3; }
    if (d_profondeur_pos < dmin) { dmin = d_profondeur_pos; idx = 4; }
    if (d_profondeur_neg < dmin) { dmin = d_profondeur_neg; idx = 5; }
    return idx;
}


Vecteur3D Brique::PointPlusProche(Vecteur3D const& x_i) const {
    Vecteur3D local = x_i - centre;
    double proj_longueur = local | dir_longueur;
    double proj_largeur = local | dir_largeur;
    double proj_profondeur = local | dir_profondeur;


    bool dedans = ((proj_longueur >= -demi_longueur) and (proj_longueur <= demi_longueur) and (proj_largeur >= -demi_largeur) and (proj_largeur <= demi_largeur) and (proj_profondeur >= -demi_profondeur) and (proj_profondeur <= demi_profondeur));


    if (not dedans) {
        if (proj_longueur < -demi_longueur) proj_longueur = -demi_longueur;
        if (proj_longueur > demi_longueur) proj_longueur = demi_longueur;
        if (proj_largeur < -demi_largeur) proj_largeur = -demi_largeur;
        if (proj_largeur > demi_largeur) proj_largeur = demi_largeur;
        if (proj_profondeur < -demi_profondeur) proj_profondeur = -demi_profondeur;
        if (proj_profondeur > demi_profondeur) proj_profondeur = demi_profondeur;
    } else {
        int face = facePlusProche(demi_longueur - proj_longueur, demi_longueur + proj_longueur, demi_largeur - proj_largeur, demi_largeur + proj_largeur, demi_profondeur - proj_profondeur, demi_profondeur + proj_profondeur);
        if (face == 0) proj_longueur = demi_longueur;
        else if (face == 1) proj_longueur = -demi_longueur;
        else if (face == 2) proj_largeur = demi_largeur;
        else if (face == 3) proj_largeur = -demi_largeur;
        else if (face == 4) proj_profondeur = demi_profondeur;
        else proj_profondeur = -demi_profondeur;
    }
    return centre + proj_longueur*dir_longueur + proj_largeur*dir_largeur + proj_profondeur*dir_profondeur;
}


void Brique::collision(Particule& p) {
    Vecteur3D local = p.get_position() - centre;
    double proj_longueur = local | dir_longueur;
    double proj_largeur = local | dir_largeur;
    double proj_profondeur = local | dir_profondeur;


    if ((proj_longueur < -demi_longueur) or (proj_longueur > demi_longueur) or (proj_largeur < -demi_largeur) or (proj_largeur > demi_largeur) or (proj_profondeur < -demi_profondeur) or (proj_profondeur > demi_profondeur)) return;


    int face = facePlusProche(demi_longueur - proj_longueur, demi_longueur + proj_longueur, demi_largeur - proj_largeur, demi_largeur + proj_largeur, demi_profondeur - proj_profondeur, demi_profondeur + proj_profondeur);
    Vecteur3D n;
    if (face == 0) n = dir_longueur;
    else if (face == 1) n = -dir_longueur;
    else if (face == 2) n = dir_largeur;
    else if (face == 3) n = -dir_largeur;
    else if (face == 4) n = dir_profondeur;
    else n = -dir_profondeur;


    // Rebond : v' = v - (1+e)(v·n)n  avec e=1 élastique, e=0 parfaitement inélastique
    Vecteur3D vitesse = p.get_vitesse();
    double vitesse_normale = vitesse | n;
    if (vitesse_normale < 0.0) p.setVitesse(vitesse - (1.0 + restitution)*vitesse_normale*n);
}


std::ostream& Brique::affiche(std::ostream& os) const {
    os << "Brique — centre: " << centre
       << ", dimensions: " << 2.0*demi_longueur << " x " << 2.0*demi_largeur << " x " << 2.0*demi_profondeur;
    return os;
}
