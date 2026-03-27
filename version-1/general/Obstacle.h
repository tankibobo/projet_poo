#include "Vecteur3D.h"

class Obstacle {
public:
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;
    virtual ~Obstacle() {}
};