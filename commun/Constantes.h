#pragma once
#include "Vecteur3D/Vecteur3D.h"
#include <cmath>


// en mm, mg, s
// f gaffe aux unités pcq la force est en "mili-newton"
namespace Constantes {
    inline const Vecteur3D g = Vecteur3D(0, 0, -9.81e3);
    inline constexpr double mv_air = 1.3e-3;
    inline constexpr double mv_eau = 1.0;
    inline constexpr double viscosite_air = 1.8e-2;
    inline constexpr double viscosite_eau = 1.0;
    inline constexpr double pi = M_PI;
    inline constexpr double dt = 0.001; // intervalle de deplacement/de calcul de force d'un système
    inline constexpr double x_repulsif = 1.12; // passage a une force repulsive dans le LJ 
    inline constexpr double p = 1e-10; // marge de comparaison entre les vecteurs
}
