#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
#include "Constantes.h"

void Vecteur3D::set_coord(std::size_t x, double k) {
	vecteur[x] = k;
}
std::ostream& operator<<(std::ostream& os, const Vecteur3D& v) {
	os << v.getX() << " " << v.getY() << " " << v.getZ();
	return os;
}	
bool operator==(const Vecteur3D& v1, const Vecteur3D& v2) {
	if((std::abs(v1.getX() - v2.getX()) <= Constantes::p) and (std::abs(v1.getY() - v2.getY()) <= Constantes::p) and (std::abs(v1.getZ() - v2.getZ()) <= Constantes::p)) {
		return true;
	}
	return false;
}
Vecteur3D operator^(Vecteur3D v1, const Vecteur3D& v2) {
	(v1^=v2);
	return v1;
}
Vecteur3D operator*(const Vecteur3D& v, double k) {
	return Vecteur3D(k*v.getX(), k*v.getY(), k*v.getZ());
}
Vecteur3D operator~(const Vecteur3D& v) {
	if(v.norme() <= Constantes::p) {return Vecteur3D(0,0,0);}
	return v/(v.norme());
}
double operator|(const Vecteur3D& v1, const Vecteur3D& v2) {
	return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}
Vecteur3D operator+(Vecteur3D v1, const Vecteur3D& v2) {v1+=v2; return v1;}
Vecteur3D operator*(double k, const Vecteur3D& v) {return v*k;}
Vecteur3D operator-(const Vecteur3D& v) {return (-1)*v;}
Vecteur3D operator-(Vecteur3D v1, const Vecteur3D& v2) {v1-=v2; return v1;}
Vecteur3D operator/(const Vecteur3D& v, double k) {return (1/k)*v;}
