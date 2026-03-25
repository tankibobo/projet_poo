// git pull [...] git add ., git commit -m "message", git push
#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
using namespace std;

void Vecteur3D::set_coord(const double& k, const double& x) {
	for(size_t i(0); i < 2; i++) {
		if(abs(vecteur[i] - x) <= 0.00001) {
			vecteur[i] = k;
		}
	}
}
ostream& operator<<(ostream& os, const Vecteur3D& v) {
	os << v.getX() << " " << v.getY() << " " << v.getZ();
	return os;
}	
bool operator==(const Vecteur3D& v1, const Vecteur3D& v2) {
	if((abs(v1.getX() - v2.getX()) <= v1.getP()) and (abs(v1.getY() - v2.getY()) <= v1.getP()) and (abs(v1.getZ() - v2.getZ()) <= v1.getP())) {
		return true;
	}
	return false;
}
Vecteur3D operator^(Vecteur3D v1, const Vecteur3D& v2) {
	(v1^=v2); 
	return v1;
}
Vecteur3D operator*(const Vecteur3D& v, const double& k) {
	return Vecteur3D(k*v.getX(), k*v.getY(), k*v.getZ());
}
Vecteur3D operator~( const Vecteur3D& v) {
	return v/(v.norme());
}
double operator|(const Vecteur3D& v1, const Vecteur3D& v2) {
	return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}
Vecteur3D operator+(Vecteur3D v1, const Vecteur3D& v2) {v1+=v2; return v1;}
Vecteur3D operator*(const double& k, const Vecteur3D& v) {return v*k;};
Vecteur3D operator-(const Vecteur3D& v) {return (-1)*v;}
Vecteur3D operator-(Vecteur3D v1, const Vecteur3D& v2) {v1-=v2; return v1;}
Vecteur3D operator/(const Vecteur3D& v, const double& k) {return (1/k)*v;};