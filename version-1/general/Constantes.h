#pragma once 
#include "Vecteur3D.h"

// en mm, mg, s
// faire gaffe aux unités car la force est en "mili-newton"
namespace Constantes {
    inline const Vecteur3D g = Vecteur3D(0, 0, -9.81e3);
    inline constexpr double mv_air = 1.3;
    inline constexpr double mv_eau = 1000;
    inline constexpr double viscosite_air = 1.8e-5;
    inline constexpr double viscosite_eau = 1e-3; 
    inline constexpr double pi = 3.14159265358979323846;
}