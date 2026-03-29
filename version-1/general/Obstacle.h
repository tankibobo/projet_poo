#include "Vecteur3D.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class Obstacle : public Dessinable {
public:
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;
    virtual ~Obstacle() {}
    virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }
};

//ajoute l'operateur d'affichage << en t'inspirant de celui pour vecteur3D: nE LE MET PAS EN SURCHARGE INTERNE C TOUJOURS EN EXTERNE 
/*ostream& operator<<(ostream& os, const Vecteur3D& v) {
	os << v.getX() << " " << v.getY() << " " << v.getZ();
	return os;
}*/