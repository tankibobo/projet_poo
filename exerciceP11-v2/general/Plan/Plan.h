#pragma once
#include "Vecteur3D/Vecteur3D.h"
#include "Obstacle/Obstacle.h"
#include "SupportADessin/SupportADessin.h"


#include <ostream>


class Plan : public Obstacle {
    public:
        Plan() : position(0,0,0), normale(0,0,1) {};
        Plan(double a, double b, double c) : position(0,0,0), normale(a, b, c) {
            normale = ~normale;
        };
        Plan(const Vecteur3D& vect) : position(0,0,0), normale(vect) {
            normale = ~normale;
        };
        Plan(double x, double y, double z, const Vecteur3D& vect) : position(x,y,z), normale(vect) {
            normale = ~normale;
        };
        Plan(double x, double y, double z, double a, double b, double c) : position(x,y,z), normale(a,b,c) {
            normale = ~normale;
        };
        Plan(const Vecteur3D& pos, const Vecteur3D& vect) : position(pos), normale(vect) {
            normale = ~normale;
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
        Dalle(double x, double y, double z, const Vecteur3D& vect, double l, double L, const Vecteur3D& dir)
            : Plan(x, y, z, vect), longueur(l), largeur(L), direction_longueur(dir)
        {
            direction_longueur = ~direction_longueur;
            // direction_largeur = normale × direction_longueur, puis normalisée
            direction_largeur = ~(normale ^ direction_longueur);
        };


        double getLongueur() const {return longueur;}
        double getLargeur() const {return largeur;}
        Vecteur3D getDirection_longueur() const {return direction_longueur;}
        Vecteur3D getDirection_largeur() const {return direction_largeur;}


        // Retourne le point de la dalle le plus proche de x_i
        Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;


        virtual std::ostream& affiche(std::ostream& os) const override;


    private:
        double longueur;
        double largeur;
        Vecteur3D direction_longueur;
        Vecteur3D direction_largeur;
};
