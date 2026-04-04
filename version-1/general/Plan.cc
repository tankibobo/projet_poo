#include "Plan.h"
#include "Vecteur3D.h"
using namespace std;


// a voir le return est peut être l'opposé de ce que je veux (negatif)
Vecteur3D Plan::PointPlusProche(Vecteur3D const& x_i) const {
    Vecteur3D x_i_p = Vecteur3D(position.getX(), position.getY(), position.getZ()) - x_i;
    double d = x_i_p | normale;
    return x_i + d*normale;
}

ostream& operator<<(ostream& os, const Plan& p) {
	os << "Plan d'origine: " << p.getPos() << " et de normale: (" << p.getNormale() << ")";
	return os;
}