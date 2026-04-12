// J'avoue je suis pas trop sûr que les obstacles sont tous considérés comme des plans, pour l'instant je fais comme ça et puis j'aviserai si je dois faire une classe obstacle ou pas, mais pour l'instant je pense que c'est pas nécessaire
#pragma once
#include "Vecteur3D.h"
#include "Obstacle.h"
#include <iostream>

class Plan : public Obstacle {
    public:
        Plan() : position(0,0,0), normale(0,0,1) {};
        Plan(const double& a, const double& b, const double& c) : position(0,0,0), normale(a, b, c) {
            ~normale;
        };
        Plan(const Vecteur3D& vect) : position(0,0,0), normale(vect) {
            ~normale;
        };
        Plan(const double& x, const double& y, const double& z, const Vecteur3D& vect) : position(x,y,z), normale(vect) {
            ~normale;
        };
        Plan(const double& x, const double& y, const double& z, const double& a, const double& b, const double& c) : position(x,y,z), normale(a,b,c) {
            ~normale;
        };
        Plan(const Vecteur3D& pos, const Vecteur3D& vect) : position(pos), normale(vect) {
            ~normale;
        };
    
        // Plan(const Plan& autre) : position(autre.position), normale(autre.normale) {}; constructeur de copie par def
        double getX() const {return position.getX();}
        double getY() const {return position.getY();}
        double getZ() const {return position.getZ();}
        Vecteur3D getPos() const {return position;}
        Vecteur3D getNormale() const {return normale;}
        virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); }
        Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
        virtual std::ostream& affiche(std::ostream& os) const override;
    protected:
        Vecteur3D position;
        Vecteur3D normale;
    
};

class Dalle : public Plan {
    public:
        Dalle(const double& x, const double& y, const double& z, const Vecteur3D& vect, const double& l, const double& L, const Vecteur3D& dir) : Plan(x,y,z,vect), longueur(l), largeur(L), direction_longueur(dir) {
            ~direction_longueur;
            direction_largeur = normale ^ direction_longueur;
            largeur = direction_largeur.norme();
        };
        double getLongueur() const {return longueur;}
        double getLargeur() const {return largeur;}
        Vecteur3D getDirection_longueur() const {return direction_longueur;}
        Vecteur3D getDirection_largeur() const {return direction_largeur;}
    private:
        double longueur;
        double largeur;
        Vecteur3D direction_longueur;
        Vecteur3D direction_largeur;

};