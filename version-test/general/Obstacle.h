#include "Vecteur3D.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#pragma once

class Obstacle : public Dessinable {
public:
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;
    virtual ~Obstacle() {}
    virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); };
    virtual std::ostream& affiche(std::ostream& os) const = 0;
};
std::ostream& operator<<(std::ostream& os, const Obstacle& o);