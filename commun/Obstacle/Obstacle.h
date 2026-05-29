#pragma once
#include "../Vecteur3D/Vecteur3D.h"
#include "../SupportADessin/SupportADessin.h"
#include "../Dessinable/Dessinable.h"


class Particule; // forward declaration pour collision()


class Obstacle : public Dessinable {
public:
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;

    // Par défaut collision() ne fait rien (Plan n'a rien à override pour corriger)
    // Les sous-classes (Brique, ...) peuvent l'override.
    virtual void collision(Particule&) {}

    virtual ~Obstacle() {}
    virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); };
    virtual std::ostream& affiche(std::ostream& os) const = 0;
};
std::ostream& operator<<(std::ostream& os, const Obstacle& o);
