#include "Vecteur3D.h"
#include <array>
#pragma once

class Particule {
    public:
        Particule(const double& x, const double& y, const double& z, const double& vx, const double& vy, const double& vz, const double& m, const double& mv, const double& r, const double& viscosite, const double& masse_v_milieu): position({x,y,z}), vitesse(vx,vy,vz), masse(m), masse_v(mv), rayon(r), viscosite(viscosite), masse_v_milieu(masse_v_milieu) {};
        void setPosition(const double& x, const double& y, const double& z) {position = {x,y,z};}
        void setVitesse(const double& vx, const double& vy, const double& vz) {vitesse = Vecteur3D(vx,vy,vz);}
        void setMasse(const double& m) {masse = m;}
        void setMasseV(const double& mv) {masse_v = mv;}
        void setRayon(const double& r) {rayon = r;}
        std::array<double, 3> get_position() const {return position;}
        Vecteur3D get_vitesse() const {return vitesse;}
        double getMasse() const {return masse;}
        double getMasseV() const {return masse_v;}
        double getRayon() const {return rayon;}
        double getViscosite() const {return viscosite;}
        double getMasseVMilieu() const {return masse_v_milieu;}
        double forceLJ(double const& x) const {return (24*epsilon)/(sigma*sigma*f(x/sigma));}
        Vecteur3D lambda() const;
        void ajoute_force(const Vecteur3D& v) {force += v;}
        void ajoute_force();
        void ajoute_force(const Particule& p);
        void bouger(double t);
    private:
        std::array<double, 3> position;
        Vecteur3D vitesse;
        double masse;
        double masse_v;
        double rayon;   
        Vecteur3D force;
        double f(const double& x) const;
        static constexpr double epsilon = 25;
        static constexpr double sigma = 0.885;
        double viscosite;
        double masse_v_milieu;

};
std::ostream& operator<<(std::ostream& os, const Particule& p);