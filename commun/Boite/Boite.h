#pragma once
#include "../Obstacle/Obstacle.h"
#include "../Vecteur3D/Vecteur3D.h"
#include <ostream>

// Parallélépipède rectangle. dir_profondeur est déduit par dir_longueur ^ dir_largeur.
// Force LJ via PointPlusProche() ; choc élastique via collision() après bouger().
class Boite : public Obstacle {
public:
    Boite(Vecteur3D const& centre,
          double longueur, double largeur, double profondeur,
          Vecteur3D const& dir_longueur,
          Vecteur3D const& dir_largeur);

    Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
    void collision(Particule& p) override;

    Vecteur3D getCentre()        const { return centre; }
    double    getLongueur()      const { return 2.0 * demi_longueur; }
    double    getLargeur()       const { return 2.0 * demi_largeur; }
    double    getProfondeur()    const { return 2.0 * demi_profondeur; }
    Vecteur3D getDirLongueur()   const { return dir_longueur; }
    Vecteur3D getDirLargeur()    const { return dir_largeur; }
    Vecteur3D getDirProfondeur() const { return dir_profondeur; }

    virtual std::ostream& affiche(std::ostream& os) const override;

private:
    Vecteur3D centre;
    double demi_longueur, demi_largeur, demi_profondeur;
    Vecteur3D dir_longueur, dir_largeur, dir_profondeur;
};
