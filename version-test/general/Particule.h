#include "Vecteur3D.h"
#include "Plan.h"
#include <array>
#include "Constantes.h"
#include "SupportADessin.h"
#include "Dessinable.h"
#pragma once

class Particule : public Dessinable {
    public:
        // constructeurs
        Particule() = delete;
        Particule(double x, double y, double z, double vx, double vy, double vz, double mv, double r, double visc, double masse_v_milieu): position(x,y,z), vitesse(vx,vy,vz), masse_v(mv), rayon(r), viscosite(visc), masse_v_milieu(masse_v_milieu), masse((4.0/3.0)*Constantes::pi*r*r*r*mv) {};
        Particule(double x, double y, double z, double mv, double r, double visc, double masse_v_milieu): position(x,y,z), vitesse(0,0,0), masse_v(mv), rayon(r), viscosite(visc), masse_v_milieu(masse_v_milieu), masse((4.0/3.0)*Constantes::pi*r*r*r*mv) {};
        Particule(double mv, double r, double visc, double masse_v_milieu): position(0,0,0), vitesse(0,0,0), masse_v(mv), rayon(r), viscosite(visc), masse_v_milieu(masse_v_milieu), masse((4.0/3.0)*Constantes::pi*r*r*r*mv) {};
        // setters
        void setPosition(const double& x, const double& y, const double& z) {position = Vecteur3D(x,y,z);}
        void setVitesse(const double& vx, const double& vy, const double& vz) {vitesse = Vecteur3D(vx,vy,vz);}
        void setVitesse(const Vecteur3D& v) {vitesse = v;}
        void setMasseV(const double& mv) {masse_v = mv;}
        void setRayon(const double& r) {rayon = r;}
        // getters
        Vecteur3D get_position() const {return position;}
        Vecteur3D get_vitesse() const {return vitesse;}
        double getMasseV() const {return masse_v;}
        double getRayon() const {return rayon;}
        double getViscosite() const {return viscosite;}
        double getMasseVMilieu() const {return masse_v_milieu;}
        double getMasse() const {return masse;}
        // fonctions
        static double forceLJ(double const& x) {return (24*epsilon)/(sigma*sigma*f(x/sigma));}
        Vecteur3D lambda_v() const;
        void ajouteForce(const Vecteur3D& v) {force += v;}
        void ajouteForce();
        void ajouteForce(const Particule& p);
        void ajouteForce(const Obstacle& obstacle);
        void bouger(double t);
        virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }
    private:
        // constantes
        static constexpr double epsilon = 25;
        static constexpr double sigma = 0.885;
        static double f(const double& x);
        // attributs
        Vecteur3D position;
        Vecteur3D vitesse;
        Vecteur3D force;
        double masse_v;
        double rayon; 
        double viscosite;
        double masse_v_milieu;
        double masse;

};
std::ostream& operator<<(std::ostream& os, const Particule& p);