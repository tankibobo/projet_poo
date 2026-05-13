#pragma once
#include "../Particule/Particule.h"
class ParticuleRoche;

class ParticuleNeige : public Particule {
    public:
        using Particule::ajouteForce;
        ParticuleNeige(double x, double y, double z, double vx, double vy, double vz, double mv, double r, double visc, double masse_v_milieu) : Particule(x,y,z,vx,vy,vz,mv,r,visc,masse_v_milieu) {};
        ParticuleNeige(double x, double y, double z, double mv, double r, double visc, double masse_v_milieu) : Particule(x,y,z,mv,r,visc,masse_v_milieu) {};
        ParticuleNeige(double mv, double r, double visc, double masse_v_milieu) : Particule(mv,r,visc,masse_v_milieu) {};
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