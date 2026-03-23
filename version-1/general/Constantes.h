#pragma once 
#include "Vecteur3D.h"

namespace Constantes {
    const Vecteur3D g = Vecteur3D(0, 0, -9.81);
    const double mv_air = 1.3;
    const double mv_eau = 1000;
    const double viscosite_air = 1.8e-5;
    const double viscosite_eau = 1e-3; 
    const double mv_particule = 1; //mg/mm^3
}