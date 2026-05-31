#include "Cylindre.h"
#include "Vecteur3D/Vecteur3D.h"
#include <ostream>
#include <cmath>
#include <algorithm>


Cylindre::Cylindre(Vecteur3D const& centre_, double rayon_, double hauteur_, Vecteur3D const& normale_, double restitution_, bool avec_lj_) : centre(centre_), rayon(rayon_), demi_hauteur(hauteur_/2.0), normale(~normale_), restitution(restitution_), avec_lj(avec_lj_) {
    if (restitution < 0.0 or restitution > 1.0) restitution = 1.0;
}


// Complément mathématique B.5
Vecteur3D Cylindre::PointPlusProche(Vecteur3D const& x_i) const {
    Vecteur3D e = x_i - centre;
    double en_scalaire = e | normale;
    Vecteur3D e_n = en_scalaire * normale; // composante axiale
    Vecteur3D e_u = e - e_n; // composante radiale
    double eu_norme = e_u.norme();

    // vecteur radial unitaire (u) ; si la particule est exactement sur l'axe on prend un vecteur arbitraire
    Vecteur3D u;
    if (eu_norme > 0.0) u = ~e_u;
    else u = Vecteur3D(1, 0, 0);

    // n* = signe(e·n) * n
    Vecteur3D n_star;
    if (en_scalaire >= 0.0) n_star = normale;
    else n_star = -normale;

    if (std::abs(en_scalaire) < demi_hauteur) {
        // La particule est en face de la surface latérale
        return centre + e_n + rayon * u;
    } else {
        double dist_radiale_fond = std::min(rayon, eu_norme); // limitée au rayon si la particule dépasse le bord du disque
        return centre + demi_hauteur * n_star + dist_radiale_fond * u;
    }
}


void Cylindre::collision(Particule& p) {
    Vecteur3D e = p.get_position() - centre;
    double en_scalaire = e | normale;
    Vecteur3D e_n = en_scalaire * normale;
    Vecteur3D e_u = e - e_n;
    double eu_norme = e_u.norme();

    if ((std::abs(en_scalaire) > demi_hauteur) or (eu_norme > rayon)) return;

    // Distance à la surface latérale vs distance au fond le plus proche
    double d_cote = rayon - eu_norme;
    double d_fond = demi_hauteur - std::abs(en_scalaire);

    Vecteur3D n_collision;
    if ((d_cote < d_fond) and (eu_norme > 0.0)) {
        n_collision = ~e_u;
    } else {
        if (en_scalaire >= 0.0) n_collision = normale;
        else n_collision = -normale;
    }

    // Rebond : v' = v - (1+e)(v·n̂)n̂  avec e=1 élastique, e=0 parfaitement inélastique
    Vecteur3D vitesse = p.get_vitesse();
    double vn = vitesse | n_collision;
    if (vn < 0.0) p.setVitesse(vitesse - (1.0 + restitution)*vn*n_collision);
}


std::ostream& Cylindre::affiche(std::ostream& os) const {
    os << "Cylindre — centre: " << centre << ", rayon: " << rayon << ", hauteur: " << 2.0*demi_hauteur << ", normale: " << normale;
    return os;
}
