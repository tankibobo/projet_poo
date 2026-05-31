#include "raylib_render.h"
#include "ParticuleNeige/ParticuleNeige.h"
#include "ParticuleRoche/ParticuleRoche.h"
#include "Brique/Brique.h"
#include "Constantes.h"
#include "Systeme/Systeme.h"


// ── Simulation minimale : 1 particule qui tombe sur une brique ──
// But : vérifier que la particule tombe droit et rebondit correctement,
//       et observer les énergies dans le HUD.


int main() {
    Brique* table = new Brique({0.0, 3.0, 2.0}, 10.0, 6.0, 0.4, {1,0,0}, {0,1,0});
    
    // ParticuleNeige centrée au-dessus de la brique, vitesse initiale nulle → chute libre
    Particule* neige = new ParticuleNeige(1.0, 0.15, Constantes::viscosite_air, Constantes::mv_air, {0.0, 3.0, 4.5}, {0.0, 0.0, 0.0});


    Systeme systeme({neige}, {table}, {});


    raylibRender render;
    render.run(systeme);


    return 0;
}
