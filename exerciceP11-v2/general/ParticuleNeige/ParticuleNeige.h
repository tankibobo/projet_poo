#pragma once
#include "../Particule/Particule.h"
#include "../Agent/Agent.h"
class ParticuleRoche;


class ParticuleNeige : public Particule {
    public:
        using Particule::ajouteForce;
        ParticuleNeige(double mv, double r, double visc, double mv_milieu_, Vecteur3D pos_ = {0,0,0}, Vecteur3D vit_ = {0,0,0}): Particule(mv, r, visc, mv_milieu_, pos_, vit_) {};
        virtual void ajouteForce(Agent& autre) override {autre.opere_sur(*this);}
        virtual void opere_sur(ParticuleNeige& p) override;
        virtual void opere_sur(ParticuleRoche& p) override;
        virtual Particule* copie() const override {return new ParticuleNeige(*this);}
        // getters virtuels
        virtual double getEpsilon() const override {return epsilon;}
        virtual double getSigma() const override {return sigma;}
    private:
        static constexpr double epsilon = 25;
        static constexpr double sigma = 0.885;
};
