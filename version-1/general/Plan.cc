#include "Plan.h"
#include "Vecteur3D.h"
using namespace std;

Vecteur3D Plan::PointPlusProche(Vecteur3D const& x_i) const {
    Vecteur3D x_i_p = Vecteur3D(position[0], position[1], position[2]) - x_i;
    double d = x_i_p | normale;
    return x_i + d*normale;
}