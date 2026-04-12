#pragma once 
#include "Vecteur3D.h"
#include <cmath>

// en mm, mg, s
// faire gaffe aux unités car la force est en "mili-newton"
namespace Constantes {
    inline const Vecteur3D g = Vecteur3D(0, 0, -9.81e3);
    inline constexpr double mv_air = 1.3e-3;
    inline constexpr double mv_eau = 1.0;
    inline constexpr double viscosite_air = 1.8e-2;
    inline constexpr double viscosite_eau = 1.0; 
    inline constexpr double pi = M_PI;
    inline constexpr double dt = 0.001;
}

inline double puissance(double x, int n) {
    double res(1);
    for (int i(0); i < n; ++i) {
        res *= x;
    }
    return res;
}

inline double absolue(double x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}