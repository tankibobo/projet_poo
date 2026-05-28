#include "raylib_render.h"
#include "ParticuleNeige/ParticuleNeige.h"
#include "ParticuleRoche/ParticuleRoche.h"
#include "Boite/Boite.h"
#include "Source/Source.h"
#include "Aleatoire/Aleatoire.h"
#include "Constantes.h"
#include "Systeme/Systeme.h"

int main() {
    // Semi-enclos ouvert sur le devant (face caméra) : sol + 3 murs
    Boite* sol       = new Boite({0.0, 3.0, -0.25}, 8.0, 6.0, 0.5, {1,0,0}, {0,1,0});
    Boite* murArriere = new Boite({0.0, 6.25, 3.5},  8.0, 7.0, 0.5, {1,0,0}, {0,0,1});
    Boite* murGauche  = new Boite({-4.25, 3.0, 3.5}, 6.0, 7.0, 0.5, {0,1,0}, {0,0,1});
    Boite* murDroit   = new Boite({ 4.25, 3.0, 3.5}, 6.0, 7.0, 0.5, {0,1,0}, {0,0,1});

    Aleatoire gen(42);

    ParticuleNeige modeleNeige(1.0, 0.15, Constantes::viscosite_air, Constantes::mv_air, {-1.5, 3.0, 3.5});
    Source* sourceNeige = new Source(modeleNeige, -1.5, 3.0, 3.5, 0.4, 0.02, 12.0, true, gen);

    ParticuleRoche modeleRoche(1.0, 0.2, Constantes::viscosite_air, Constantes::mv_air, {1.5, 3.0, 3.5});
    Source* sourceRoche = new Source(modeleRoche, 1.5, 3.0, 3.5, 0.3, 0.02, 8.0, true, gen);

    Systeme systeme({}, {sol, murArriere, murGauche, murDroit}, {sourceNeige, sourceRoche});

    raylibRender render;
    render.run(systeme);

    return 0;
}
