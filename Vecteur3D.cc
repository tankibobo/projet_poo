#include <iostream>
#include <cmath>
using namespace std;

class Vecteur3D {
	public:
	void set_coord(const double& cA, const double& cB) {
		for(size_t i(0); i<3; i++){
			if(vecteur[i] == cB) {
				vecteur[i] = cA;
			}
		}
		return;
	}
	void affiche() const {
		cout << vecteur[0] << " " << vecteur[1] << " " << vecteur [2] << endl;
	}
	bool compare(const Vecteur3D& autre, const double& p = 1e-10) const{
		if((abs(autre.vecteur[0]-vecteur[0]) == p) and (abs(autre.vecteur[1]-vecteur[1]) == p) and (abs(autre.vecteur[2]-vecteur[2]) == p)) {
			return true;
		}
		return false;
	}
	Vecteur3D resultat(const array<double, 3>& v) const {
		Vecteur3D resultat;
		resultat.vecteur = v;
		return resultat;
	}
	Vecteur3D addition(const Vecteur3D& autre) const {
	return resultat({vecteur[0] + autre.vecteur[0], vecteur[1] + autre.vecteur[1], vecteur[2] + autre.vecteur[2]});
	}
	Vecteur3D soustraction(const Vecteur3D& autre) const {
	return resultat({vecteur[0] - autre.vecteur[0], vecteur[1] - autre.vecteur[1], vecteur[2] - autre.vecteur[2]});
	}
	Vecteur3D oppose() const {
		return resultat({-vecteur[0], -vecteur[1], -vecteur[2]});
	}
	Vecteur3D mult(const double& k) const {
		return resultat({k*vecteur[0], k*vecteur[1], k*vecteur[2]});
	}
	Vecteur3D div(const double& k) const {
		return resultat({vecteur[0]/k, vecteur[1]/k, vecteur[2]/k});
	}
	double prod_scal(const Vecteur3D& autre) const {
		return vecteur[0]*autre.vecteur[0] + vecteur[1]*autre.vecteur[1] + vecteur[2]*autre.vecteur[2];
	}
	Vecteur3D prod_vect(const Vecteur3D& autre) const {
		return resultat({vecteur[1]*autre.vecteur[2] - vecteur[2]*autre.vecteur[1], vecteur[2]*autre.vecteur[0] - vecteur[0]*autre.vecteur[2], vecteur[0]*autre.vecteur[1] - vecteur[1]*autre.vecteur[0]});
	}
	double norme() const {
		return sqrt(vecteur[0]*vecteur[0] + vecteur[1]*vecteur[1] + vecteur[2]*vecteur[2]);
	}
	double norme2() const {
		double x(norme());
		return x*x;
	}
	Vecteur3D unitaire() const {
		double x(norme());
		return div(x);
	}
	private :
		array<double, 3> vecteur; 
};

int main() {
	
	return(0);
}
