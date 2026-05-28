#pragma once
#include "Vecteur3D/Vecteur3D.h"
#include "SupportADessin/SupportADessin.h"
#include "Dessinable/Dessinable.h"
#include "../Particule/Particule.h"
#include "../ParticuleRoche/ParticuleRoche.h"
#include "../ParticuleNeige/ParticuleNeige.h"
#include "../Agent/Agent.h"

class Obstacle : public Dessinable, public Agent {
public:
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;

    // Choc élastique après bouger() — par défaut ne fait rien (Plan infini).
    virtual void collision(Particule& /*p*/) {}

    virtual ~Obstacle() {}
    virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); };
    virtual std::ostream& affiche(std::ostream& os) const = 0;
    virtual void opere_sur(ParticuleNeige& p) override;
    virtual void opere_sur(ParticuleRoche& p) override;
    void force(Particule& p) const;
};
std::ostream& operator<<(std::ostream& os, const Obstacle& o);