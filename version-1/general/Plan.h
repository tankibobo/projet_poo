#pragma once
#include "Vecteur3D.h"
using namespace std;

class Plan {
    public:
        Plan() : position({0,0,0}), normale(0,0,1) {};
        Plan(const double& a, const double& b, const double& c) : position({0,0,0}), normale(a, b, c) {
            normale.normalise();
        };
        Plan(const Vecteur3D& vect) : position({0,0,0}), normale(vect) {
            normale.normalise();
        };
        Plan(const double& x, const double& y, const double& z, const Vecteur3D& vect) : position({x,y,z}), normale(vect) {
            normale.normalise();
        };
        Plan(const double& x, const double& y, const double& z, const double& a, const double& b, const double& c) : position({x,y,z}), normale(a,b,c) {
            normale.normalise();
        };
    
        // Plan(const Plan& autre) : position(autre.position), normale(autre.normale) {}; constructeur de copie par def
        double getX() const {return position[0];}
        double getY() const {return position[1];}
        double getZ() const {return position[2];}
        Vecteur3D getNormale() const {return normale;}

        Vecteur3D PointPlusProche(Vecteur3D const& x_i) const;
    
    protected:
        array<double, 3> position;
        Vecteur3D normale;
    
};


class Dalle : public Plan {
    public:
        Dalle(const double& x, const double& y, const double& z, const Vecteur3D& vect, const double& l, const double& L, const Vecteur3D& dir) : Plan(x,y,z,vect), longueur(l), largeur(L), direction_longueur(dir) {
            direction_longueur.normalise();
        };
        // Dalle(const Dalle& autre) : Plan(autre), longueur(autre.longueur), largeur(autre.largeur), direction(autre.direction) {}; constructeur de copie par def
        
    private:
        double longueur;
        double largeur;
        Vecteur3D direction_longueur;
        Vecteur3D direction_largeur = normale ^ direction_longueur;

};