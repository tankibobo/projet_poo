#pragma once
#include <ostream>
#include "../SupportADessin/SupportADessin.h"
#include "../Dessinable/Dessinable.h"
#include "../Vecteur3D/Vecteur3D.h"
#include "../Constantes.h"
#include "../Agent/Agent.h"
class ParticuleNeige;

class Particule : public Dessinable, public Agent {
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
        void setForce(const Vecteur3D& f) {force = f;}
        // getters
        Vecteur3D get_position() const {return position;}
        Vecteur3D get_vitesse() const {return vitesse;}
        double getMasseV() const {return masse_v;}
        double getRayon() const {return rayon;}
        double getViscosite() const {return viscosite;}
        double getMasseVMilieu() const {return masse_v_milieu;}
        double getMasse() const {return masse;}
        Vecteur3D getForce() const {return force;}
        virtual double getEpsilon() const = 0;
        virtual double getSigma() const = 0;
        // fonctions
        static double forceLJ(double const& x, double const& epsilon, double const& sigma) {return (24*epsilon)/(sigma*sigma) * f(x/sigma);}
        Vecteur3D lambda_v() const;
        void ajouteForce(const Vecteur3D& v) {force += v;}
        void ajouteForce();
        virtual void ajouteForce(Agent& autre) = 0;
        virtual void opere_sur(ParticuleNeige& p) override = 0;
        void bouger(double t);
        virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }
        virtual Particule* copie() const = 0;
        // constantes
        static double f(const double& x);
        //destructeur virtuel
        virtual ~Particule() {}
    private:
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