#include "raylib_render.h"
#include "Plan/Plan.h"
#include <raylib.h>
#include <string>

// Correspondance de coordonnées : la simulation utilise Z vers le haut,
// raylib utilise Y vers le haut.
// sim(x, y, z)  ->  ray(x, z_sim, y_sim)
static Vector3 simToRay(double x, double y, double z) {
    return { static_cast<float>(x),
             static_cast<float>(z),
             static_cast<float>(y) };
}

raylibRender::raylibRender()
    : deplacement(false)
{
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Simulation P10");

    camera.position   = { 4.0f, 6.0f, 12.0f };
    camera.target     = { 0.5f, 1.5f,  0.0f };
    camera.up         = { 0.0f, 1.0f,  0.0f };
    camera.fovy       = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);
}

raylibRender::~raylibRender()
{
    CloseWindow();
}

void raylibRender::run(Systeme& systeme)
{
    while (!WindowShouldClose()) {

        // Touche L : activer/désactiver le mouvement libre de la caméra
        if (IsKeyPressed(KEY_L)) {
            deplacement = !deplacement;
        }
        if (deplacement) {
            UpdateCamera(&camera, CAMERA_FREE);
        }

        // Avancer la simulation d'un pas de temps
        systeme.evolue();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                DrawGrid(20, 1.0f);
                systeme.dessine_sur(*this);
            EndMode3D();

            // Affichage des instructions (hors mode 3D)
            DrawText("Appuyez sur 'L' pour activer/désactiver le mouvement de la caméra", 10, 10, 16, DARKGRAY);
            DrawText((std::string("Caméra ") + (deplacement ? "libre (WASD + souris)" : "fixe")).c_str(),
                     10, 32, 16, DARKGRAY);
            DrawFPS(10, 54);
        EndDrawing();
    }
}

void raylibRender::dessine(Particule const& p)
{
    Vecteur3D pos = p.get_position();
    Vector3 rPos  = simToRay(pos.getX(), pos.getY(), pos.getZ());
    float   r     = static_cast<float>(p.getRayon());
    DrawSphere(rPos, r, BLUE);
    DrawSphereWires(rPos, r, 8, 8, DARKBLUE);
}

void raylibRender::dessine(Systeme const& s)
{
    for (auto* p : s.getParticules()) {
        p->dessine_sur(*this);
    }
    for (auto* o : s.getObstacles()) {
        o->dessine_sur(*this);
    }
    for (auto* src : s.getSources()) {
        src->dessine_sur(*this);
    }
}

void raylibRender::dessine(Obstacle const& o)
{
    // Dessiner un Plan comme une surface plate
    Plan const* plan = dynamic_cast<Plan const*>(&o);
    if (plan != nullptr) {
        Vecteur3D pos = plan->getPos();
        Vector3 rPos  = simToRay(pos.getX(), pos.getY(), pos.getZ());
        DrawPlane(rPos, { 20.0f, 20.0f }, LIGHTGRAY);
    }
}

void raylibRender::dessine(Source const& s)
{
    Vecteur3D pos = s.getPosition();
    Vector3 rPos  = simToRay(pos.getX(), pos.getY(), pos.getZ());
    DrawSphere(rPos, 0.2f, YELLOW);
}
