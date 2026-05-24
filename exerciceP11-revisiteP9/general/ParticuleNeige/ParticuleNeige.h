#pragma once
#include "../Particule/Particule.h"
#include "../Agent/Agent.h"

class ParticuleRoche;

class ParticuleNeige : public Particule {
    public:
        using Particule::ajouteForce;
        ParticuleNeige(double mv, double r, double visc, double masse_v_milieu, Vecteur3D position = {0,0,0}, Vecteur3D vitesse = {0,0,0}): Particule(mv, r, visc, masse_v_milieu, position, vitesse) {};
        virtual void ajouteForce(Agent& autre) override {autre.opere_sur(*this);}
        virtual void opere_sur(ParticuleNeige& p) override;
        virtual Particule* copie() const override {return new ParticuleNeige(*this);}
        // getters virtuels
        virtual double getEpsilon() const override {return epsilon;}
        virtual double getSigma() const override {return sigma;}
    private:
        static constexpr double epsilon = 25;
        static constexpr double sigma = 0.885;
};