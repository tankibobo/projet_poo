#include "Plan.h"
#include "../Vecteur3D/Vecteur3D.h"
using namespace std;


// a voir le return est peut être l'opposé de ce que je veux (negatif)
Vecteur3D Plan::PointPlusProche(Vecteur3D const& x_i) const {
    Vecteur3D x_i_p = position - x_i;
    double d = x_i_p | normale;
    return x_i + d*normale;
}

ostream& Plan::affiche(ostream& os) const {
	os << "Plan d'origine: " << getPos() << " et de normale: (" << getNormale() << ")";
	return os;
}