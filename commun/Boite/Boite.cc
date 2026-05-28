#include "Boite.h"
#include "Particule/Particule.h"
#include "../Vecteur3D/Vecteur3D.h"
#include <ostream>

Boite::Boite(Vecteur3D const& centre,
             double longueur, double largeur, double profondeur,
             Vecteur3D const& dir_longueur,
             Vecteur3D const& dir_largeur)
    : centre(centre)
    , demi_longueur(longueur/2.0), demi_largeur(largeur/2.0), demi_profondeur(profondeur/2.0)
    , dir_longueur(~dir_longueur), dir_largeur(~dir_largeur)
    , dir_profondeur(~(dir_longueur ^ dir_largeur))
{}

// Indice de la face la plus proche : 0/1=±longueur, 2/3=±largeur, 4/5=±profondeur
static int facePlusProche(double d_longueur_pos, double d_longueur_neg,
                          double d_largeur_pos,  double d_largeur_neg,
                          double d_profondeur_pos, double d_profondeur_neg)
{
    int idx = 0;
    double dmin = d_longueur_pos;
    if (d_longueur_neg   < dmin) { dmin = d_longueur_neg;   idx = 1; }
    if (d_largeur_pos    < dmin) { dmin = d_largeur_pos;    idx = 2; }
    if (d_largeur_neg    < dmin) { dmin = d_largeur_neg;    idx = 3; }
    if (d_profondeur_pos < dmin) { dmin = d_profondeur_pos; idx = 4; }
    if (d_profondeur_neg < dmin) { dmin = d_profondeur_neg; idx = 5; }
    return idx;
}

Vecteur3D Boite::PointPlusProche(Vecteur3D const& x_i) const {
    Vecteur3D local = x_i - centre;
    double proj_longueur   = local | dir_longueur;
    double proj_largeur    = local | dir_largeur;
    double proj_profondeur = local | dir_profondeur;

    bool dedans = (proj_longueur   >= -demi_longueur  and proj_longueur   <= demi_longueur  and
                   proj_largeur    >= -demi_largeur    and proj_largeur    <= demi_largeur   and
                   proj_profondeur >= -demi_profondeur and proj_profondeur <= demi_profondeur);

    if (not dedans) {
        if (proj_longueur   < -demi_longueur)   proj_longueur   = -demi_longueur;
        if (proj_longueur   >  demi_longueur)   proj_longueur   =  demi_longueur;
        if (proj_largeur    < -demi_largeur)     proj_largeur    = -demi_largeur;
        if (proj_largeur    >  demi_largeur)     proj_largeur    =  demi_largeur;
        if (proj_profondeur < -demi_profondeur)  proj_profondeur = -demi_profondeur;
        if (proj_profondeur >  demi_profondeur)  proj_profondeur =  demi_profondeur;
    } else {
        int face = facePlusProche(
            demi_longueur - proj_longueur,     demi_longueur + proj_longueur,
            demi_largeur  - proj_largeur,      demi_largeur  + proj_largeur,
            demi_profondeur - proj_profondeur, demi_profondeur + proj_profondeur);
        switch (face) {
            case 0: proj_longueur   =  demi_longueur;   break;
            case 1: proj_longueur   = -demi_longueur;   break;
            case 2: proj_largeur    =  demi_largeur;    break;
            case 3: proj_largeur    = -demi_largeur;    break;
            case 4: proj_profondeur =  demi_profondeur; break;
            default: proj_profondeur = -demi_profondeur; break;
        }
    }
    return centre + proj_longueur*dir_longueur + proj_largeur*dir_largeur + proj_profondeur*dir_profondeur;
}

void Boite::collision(Particule& p) {
    Vecteur3D local = p.get_position() - centre;
    double proj_longueur   = local | dir_longueur;
    double proj_largeur    = local | dir_largeur;
    double proj_profondeur = local | dir_profondeur;

    if (proj_longueur   < -demi_longueur  or proj_longueur   > demi_longueur  or
        proj_largeur    < -demi_largeur   or proj_largeur    > demi_largeur   or
        proj_profondeur < -demi_profondeur or proj_profondeur > demi_profondeur) return;

    int face = facePlusProche(
        demi_longueur - proj_longueur,     demi_longueur + proj_longueur,
        demi_largeur  - proj_largeur,      demi_largeur  + proj_largeur,
        demi_profondeur - proj_profondeur, demi_profondeur + proj_profondeur);
    Vecteur3D n;
    switch (face) {
        case 0: n =  dir_longueur;   break;
        case 1: n = -dir_longueur;   break;
        case 2: n =  dir_largeur;    break;
        case 3: n = -dir_largeur;    break;
        case 4: n =  dir_profondeur; break;
        default: n = -dir_profondeur; break;
    }

    // Réflexion élastique : v' = v - 2(v·n̂)n̂
    Vecteur3D vitesse = p.get_vitesse();
    double vitesse_normale = vitesse | n;
    if (vitesse_normale < 0.0) p.setVitesse(vitesse - 2.0*vitesse_normale*n);
}

std::ostream& Boite::affiche(std::ostream& os) const {
    os << "Boite — centre: " << centre
       << ", dimensions: " << 2.0*demi_longueur << " x " << 2.0*demi_largeur << " x " << 2.0*demi_profondeur;
    return os;
}
