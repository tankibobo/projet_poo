#pragma once
#include "Vecteur3D/Vecteur3D.h"
#include "SupportADessin/SupportADessin.h"
#include "Dessinable/Dessinable.h"
#include "../Agent/Agent.h"

class Particule;
class ParticuleRoche;
class ParticuleNeige;

class Obstacle : public Dessinable, public Agent {
public:
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;

    // Choc élastique après bouger() ; on a enlevé le nom de variable pour éviter les warnings.
    virtual void collision(Particule&) {}

    virtual ~Obstacle() {}
    virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); };
    virtual std::ostream& affiche(std::ostream& os) const = 0;
    virtual void opere_sur(ParticuleNeige& p) override;
    virtual void opere_sur(ParticuleRoche& p) override;
    void force(Particule& p) const;
};
std::ostream& operator<<(std::ostream& os, const Obstacle& o);