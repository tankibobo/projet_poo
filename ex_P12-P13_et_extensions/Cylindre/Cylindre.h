#pragma once
#include "../Obstacle/Obstacle.h"
#include "../ParticuleNeige/ParticuleNeige.h"
#include "../ParticuleRoche/ParticuleRoche.h"
#include "Vecteur3D/Vecteur3D.h"
#include <ostream>


// La normale pointe le long de l'axe du cylindre.
class Cylindre : public Obstacle {
public:
    Cylindre(Vecteur3D const& centre_, double rayon_, double hauteur_, Vecteur3D const& normale_, double restitution_ = 1.0, bool avec_lj_ = true);


    virtual void opere_sur(ParticuleNeige& p) override { if (avec_lj) force(p); }
    virtual void opere_sur(ParticuleRoche& p) override { if (avec_lj) force(p); }


    Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
    void collision(Particule& p) override;


    Vecteur3D getCentre() const { return centre; }
    double getRayon() const { return rayon; }
    double getHauteur() const { return 2.0 * demi_hauteur; }
    Vecteur3D getNormale() const { return normale; }
    double getRestitution() const { return restitution; }


    virtual std::ostream& affiche(std::ostream& os) const override;


private:
    Vecteur3D centre;
    double rayon;
    double demi_hauteur;
    Vecteur3D normale;     // axe du cylindre (unitaire)
    double restitution;    // coefficient de restitution entre [0, 1]
    bool avec_lj;          // true = force LJ active, false = choc uniquement
};
