// AVANT DE COMMECNER: TAPER git.pull, , une fois fini taper git.push
// inverser const et vecteur3d&: VECTEUR3D& CONST 
#include <array>
#include <iostream>
#pragma once

class Vecteur3D {
	public:
	// constructeurs
	Vecteur3D(): vecteur({0,0,0}) {};
	Vecteur3D(const double& x, const double& y, const double& z): vecteur({x,y,z}) {};
	// coordonnées (setters)
	void def_coord(const double& x, const double& y, const double& z) {vecteur = {x,y,z};}
	void set_coord(const double& x, const double& y);
	// getters
	double getX() const {return vecteur[0];}
	double getY() const {return vecteur[1];}
	double getZ() const {return vecteur[2];}
	double getP() const {return p;}
	// normes
	double norme() const {return sqrt(vecteur[0]*vecteur[0] + vecteur[1]*vecteur[1] + vecteur[2]*vecteur[2]);}
	double norme2() const {double x(norme()); return x*x;}
	// opérateurs
	void operator+=(const Vecteur3D& autre) {vecteur = {autre.getX() + vecteur[0], autre.getY() + vecteur[1], autre.getZ() + vecteur[2]};}
	void operator-=(const Vecteur3D& autre) {vecteur = {vecteur[0] - autre.getX(), vecteur[1] - autre.getY(), vecteur[2] - autre.getZ()};}
	void operator*=(const double& k) {vecteur = {k*vecteur[0], k*vecteur[1], k*vecteur[2]};}
	void operator/=(const double& k) {vecteur = {vecteur[0]/k, vecteur[1]/k, vecteur[2]/k};}
	void operator^=(const Vecteur3D& autre) {vecteur = {vecteur[1] * autre.getZ() - vecteur[2] * autre.getY(), vecteur[2] * autre.getX() - vecteur[0] * autre.getZ(), vecteur[0] * autre.getY() - vecteur[1] * autre.getX()};}

	private :
		std::array<double, 3> vecteur; 
		static constexpr double p = 1e-10;
};

std::ostream& operator<<(std::ostream& os, const Vecteur3D& v);
bool operator==(const Vecteur3D& v1, const Vecteur3D& v2);
Vecteur3D operator+(Vecteur3D v1, const Vecteur3D& v2);
Vecteur3D operator*(const Vecteur3D& v, const double& k);
Vecteur3D operator*(const double& k, const Vecteur3D& v);
Vecteur3D operator-(const Vecteur3D& v);
Vecteur3D operator-(Vecteur3D v1, const Vecteur3D& v2);
Vecteur3D operator^(Vecteur3D v1, const Vecteur3D& v2); // produit vectoriel
Vecteur3D operator/(const Vecteur3D& v, const double& k);
Vecteur3D operator/(const double& k, const Vecteur3D& v);
Vecteur3D operator~(const Vecteur3D& v); // unitaire
double operator|(const Vecteur3D& v1, const Vecteur3D& v2); // produit scalaire
