#pragma once
#include "../Particule/Particule.h"
#include "../Agent/Agent.h"
#include "../ParticuleNeige/ParticuleNeige.h"

class ParticuleRoche : public Particule {
    public:
        using Particule::ajouteForce;
        ParticuleRoche(double mv, double r, double visc, double masse_v_milieu, Vecteur3D position = {0,0,0}, Vecteur3D vitesse = {0,0,0}): Particule(mv, r, visc, masse_v_milieu, position, vitesse) {};
        virtual void ajouteForce(Agent& autre) override {autre.opere_sur(*this);}
        virtual void opere_sur(ParticuleNeige& p) override;
        virtual void opere_sur(ParticuleRoche& p) override;
        virtual Particule* copie() const override {return new ParticuleRoche(*this);}
        // getters virtuels
        virtual double getEpsilon() const override {return epsilon;}
        virtual double getSigma() const override {return sigma;}
    private:
        static constexpr double epsilon = 45;
        static constexpr double sigma = 0.6;
};