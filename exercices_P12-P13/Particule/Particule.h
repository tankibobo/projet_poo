#pragma once
#include <array>
#include "SupportADessin/SupportADessin.h"
#include "Dessinable/Dessinable.h"
#include "Vecteur3D/Vecteur3D.h"
#include "Constantes.h"
#include "Plan/Plan.h"
#include "Obstacle/Obstacle.h"

class Particule : public Dessinable {
    public:
        // constructeurs
        Particule() = delete;
        Particule(double mv, double r, double visc, double masse_v_milieu, Vecteur3D pos_ = {0,0,0}, Vecteur3D vit_ = {0,0,0}): position(pos_), vitesse(vit_), masse_v(mv), rayon(r), viscosite(visc), masse_v_milieu(masse_v_milieu), masse((4.0/3.0)*Constantes::pi*r*r*r*mv) {};
        void setVitesse(const Vecteur3D& v) {vitesse = v;}
        void setRayon(const double& r) {rayon = r; masse = (4.0/3.0)*Constantes::pi*rayon*rayon*rayon*masse_v;}
        void setX(const int& x) {x_grille = x;}
        void setY(const int& y) {y_grille = y;}
        void setZ(const int& z) {z_grille = z;}
        // getters
        Vecteur3D get_position() const {return position;}
        Vecteur3D get_vitesse() const {return vitesse;}
        double getMasseV() const {return masse_v;}
        double getRayon() const {return rayon;}
        double getViscosite() const {return viscosite;}
        double getMasseVMilieu() const {return masse_v_milieu;}
        double getMasse() const {return masse;}
        int getX() const {return x_grille;}
        int getY() const {return y_grille;}
        int getZ() const {return z_grille;}
        double getSigma() const {return sigma;}
        // fonctions
        static double forceLJ(double const& x) {return (24*epsilon)/(sigma*sigma) * f(x/sigma);}
        Vecteur3D lambda_v() const;
        void ajouteForce(const Vecteur3D& v) {force += v;}
        void ajouteForce();
        void ajouteForce(Particule& p);
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
        int x_grille;
        int y_grille;
        int z_grille;
};
std::ostream& operator<<(std::ostream& os, const Particule& p);