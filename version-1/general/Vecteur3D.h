// AVANT DE COMMECNER: TAPER git.pull, , une fois fini taper git.push
#include <cmath>
#include <array>
#pragma once

class Vecteur3D {
	public:
	Vecteur3D(double x = 0, double y = 0, double z = 0) 
        : vecteur({x, y, z})
    {}
	void set_coord(const double& x, const double& y, const double& z) {vecteur = {x,y,z};}
	void affiche() const;
	bool compare(const Vecteur3D& autre, const double& p = 1e-10) const;
	Vecteur3D addition(const Vecteur3D& autre) const;
	Vecteur3D soustraction(const Vecteur3D& autre) const;
	Vecteur3D oppose() const {return resultat({-vecteur[0], -vecteur[1], -vecteur[2]});}
	Vecteur3D mult(const double& k) const {return resultat({k*vecteur[0], k*vecteur[1], k*vecteur[2]});}
	Vecteur3D div(const double& k) const {return resultat({vecteur[0]/k, vecteur[1]/k, vecteur[2]/k});}
	double prod_scal(const Vecteur3D& autre) const;
	Vecteur3D prod_vect(const Vecteur3D& autre) const;
	double norme() const {return sqrt(vecteur[0]*vecteur[0] + vecteur[1]*vecteur[1] + vecteur[2]*vecteur[2]);}
	double norme2() const {double x(norme()); return x*x;}
	Vecteur3D unitaire() const;
	private :
		std::array<double, 3> vecteur; 
		Vecteur3D resultat(const std::array<double, 3>& v) const;
};
