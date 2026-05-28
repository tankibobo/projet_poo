#pragma once
#include "../Vecteur3D/Vecteur3D.h"
#include "../SupportADessin/SupportADessin.h"
#include "../Dessinable/Dessinable.h"

class Particule;  // forward declaration pour collision()

class Obstacle : public Dessinable {
public:
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;

    // Résolution d'un choc élastique après le déplacement.
    // Par défaut : ne fait rien (Plan infini → jamais de pénétration à corriger).
    // Les sous-classes finies (Boite, ...) peuvent l'override.
    virtual void collision(Particule&) {}

    virtual ~Obstacle() {}
    virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); };
    virtual std::ostream& affiche(std::ostream& os) const = 0;
};
std::ostream& operator<<(std::ostream& os, const Obstacle& o);