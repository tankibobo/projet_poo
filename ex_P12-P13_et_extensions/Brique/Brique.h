#pragma once
#include "../Obstacle/Obstacle.h"
#include "../ParticuleNeige/ParticuleNeige.h"
#include "../ParticuleRoche/ParticuleRoche.h"
#include "Vecteur3D/Vecteur3D.h"
#include <ostream>


// Parallélépipède rectangle. dir_profondeur est déduit par dir_longueur ^ dir_largeur.
class Brique : public Obstacle {
public:
    // restitution_ : coefficient de restitution (1.0 = élastique, 0.0 = parfaitement inélastique)
    Brique(Vecteur3D const& centre_, double longueur, double largeur, double profondeur, Vecteur3D const& dir_longueur_, Vecteur3D const& dir_largeur_, double restitution_ = 1.0);


    virtual void opere_sur(ParticuleNeige& p) override { force(p); }
    virtual void opere_sur(ParticuleRoche& p) override { force(p); }


    Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
    void collision(Particule& p) override;


    Vecteur3D getCentre() const { return centre; }
    double getLongueur() const { return 2.0 * demi_longueur; }
    double getLargeur() const { return 2.0 * demi_largeur; }
    double getProfondeur() const { return 2.0 * demi_profondeur; }
    Vecteur3D getDirLongueur() const { return dir_longueur; }
    Vecteur3D getDirLargeur() const { return dir_largeur; }
    Vecteur3D getDirProfondeur() const { return dir_profondeur; }
    double getRestitution() const { return restitution; }


    virtual std::ostream& affiche(std::ostream& os) const override;


private:
    Vecteur3D centre;
    double demi_longueur, demi_largeur, demi_profondeur;
    Vecteur3D dir_longueur, dir_largeur, dir_profondeur;
    double restitution;    // coefficient de restitution entre [0, 1]
};
