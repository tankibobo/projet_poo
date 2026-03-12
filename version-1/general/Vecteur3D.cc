// git pull [...] git add ., git commit -m "message", git push
#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
#include <array>
using namespace std;

void Vecteur3D::affiche() const {
	cout << vecteur[0] << " " << vecteur[1] << " " << vecteur [2] << endl;
}
void Vecteur3D::set_coord(const double& k, const double& x) {
	for(size_t i(0); i < 2; i++) {
		if(std::abs(vecteur[i] - x) <= 0.001) {
			vecteur[i] = k;
		}
	}
}	
bool Vecteur3D::compare(const Vecteur3D& autre, const double& p) const{
	if((std::abs(autre.vecteur[0]-vecteur[0]) <= p) and (std::abs(autre.vecteur[1]-vecteur[1]) <= p) and (std::abs(autre.vecteur[2]-vecteur[2]) <= p)) {
		return true;
	}
	return false;
}
Vecteur3D Vecteur3D::addition(const Vecteur3D& autre) const {
return resultat({vecteur[0] + autre.vecteur[0], vecteur[1] + autre.vecteur[1], vecteur[2] + autre.vecteur[2]});
}
Vecteur3D Vecteur3D::soustraction(const Vecteur3D& autre) const {
return resultat({vecteur[0] - autre.vecteur[0], vecteur[1] - autre.vecteur[1], vecteur[2] - autre.vecteur[2]});
}
double Vecteur3D::prod_scal(const Vecteur3D& autre) const {
	return vecteur[0]*autre.vecteur[0] + vecteur[1]*autre.vecteur[1] + vecteur[2]*autre.vecteur[2];
}
Vecteur3D Vecteur3D::prod_vect(const Vecteur3D& autre) const {
	return resultat({vecteur[1]*autre.vecteur[2] - vecteur[2]*autre.vecteur[1], vecteur[2]*autre.vecteur[0] - vecteur[0]*autre.vecteur[2], vecteur[0]*autre.vecteur[1] - vecteur[1]*autre.vecteur[0]});
}
Vecteur3D Vecteur3D::unitaire() const {
	double x(norme());
	return div(x);
}
Vecteur3D Vecteur3D::resultat(const array<double, 3>& v) const {
		Vecteur3D r(v[0], v[1], v[2]);
		return r;
	}
