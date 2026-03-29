#include "Vecteur3D.h"
#include "Plan.h"
#include <array>
#include "Constantes.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#pragma once

class Particule : public Dessinable {
    public:
        Particule(const double& x, const double& y, const double& z, const double& vx, const double& vy, const double& vz, const double& mv, const double& r, const double& viscosite, const double& masse_v_milieu): position(x,y,z), vitesse(vx,vy,vz), masse_v(mv), rayon(r), viscosite(viscosite), masse_v_milieu(masse_v_milieu) {};
        void setPosition(const double& x, const double& y, const double& z) {position = Vecteur3D(x,y,z);}
        void setVitesse(const double& vx, const double& vy, const double& vz) {vitesse = Vecteur3D(vx,vy,vz);}
        void setVitesse(const Vecteur3D& v) {vitesse = v;}
        void setMasseV(const double& mv) {masse_v = mv;}
        void setRayon(const double& r) {rayon = r;}
        Vecteur3D get_position() const {return position;}
        Vecteur3D get_vitesse() const {return vitesse;}
        double getMasseV() const {return masse_v;}
        double getRayon() const {return rayon;}
        double getViscosite() const {return viscosite;}
        double getMasseVMilieu() const {return masse_v_milieu;}
        static double forceLJ(double const& x) {return (24*epsilon)/(sigma*sigma*f(x/sigma));}
        double getMasse() const {return (4.0/3.0)*Constantes::pi*rayon*rayon*rayon*masse_v;} //éviter d'include cmath
        Vecteur3D lambda_v() const;
        void ajoute_force(const Vecteur3D& v) {force += v;}
        void ajoute_force();
        void ajoute_force(const Particule& p);
        void ajoute_force(const Obstacle& obstacle);
        void bouger(double t);
        virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }
    private:
        Vecteur3D position;
        Vecteur3D vitesse;
        double masse_v;
        double rayon; 
        Vecteur3D force;
        static double f(const double& x);
        static constexpr double epsilon = 25;
        static constexpr double sigma = 0.885;
        double viscosite;
        double masse_v_milieu;

};
std::ostream& operator<<(std::ostream& os, const Particule& p);