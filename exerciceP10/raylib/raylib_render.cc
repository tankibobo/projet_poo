#include "raylib_render.h"
#include "../general/Plan/Plan.h"
#include <raylib.h>

// Coordinate mapping: simulation uses Z-up, raylib uses Y-up
// sim(x, y, z)  ->  ray(x, z_sim, y_sim)
static Vector3 simToRay(double x, double y, double z) {
    return { static_cast<float>(x),
             static_cast<float>(z),
             static_cast<float>(y) };
}

raylibRender::raylibRender()
{
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Simulation P10");

    camera.position   = { 5.0f, 5.0f, 5.0f };
    camera.target     = { 0.0f, 0.0f, 0.0f };
    camera.up         = { 0.0f, 1.0f, 0.0f };
    camera.fovy       = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    cameraMode = CAMERA_ORBITAL;

    DisableCursor();
    SetTargetFPS(60);
}

raylibRender::~raylibRender()
{
    CloseWindow();
}

void raylibRender::run(Systeme& systeme)
{
    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_ONE)) {
            cameraMode = CAMERA_FREE;
            camera.up  = { 0.0f, 1.0f, 0.0f };
        }
        if (IsKeyPressed(KEY_TWO)) {
            cameraMode = CAMERA_FIRST_PERSON;
            camera.up  = { 0.0f, 1.0f, 0.0f };
        }
        if (IsKeyPressed(KEY_THREE)) {
            cameraMode = CAMERA_THIRD_PERSON;
            camera.up  = { 0.0f, 1.0f, 0.0f };
        }
        if (IsKeyPressed(KEY_FOUR)) {
            cameraMode = CAMERA_ORBITAL;
            camera.up  = { 0.0f, 1.0f, 0.0f };
        }

        systeme.evolue();

        // Make the camera target track the centre of mass of all particles
        // so they stay visible even as they fall through the floor (known
        // physics limitation: LJ repulsion < gravity with the given epsilon).
        {
            auto const& particules = systeme.getParticules();
            if (!particules.empty()) {
                double cx = 0, cy = 0, cz = 0;
                for (auto const* p : particules) {
                    cx += p->get_position().getX();
                    cy += p->get_position().getY();
                    cz += p->get_position().getZ();
                }
                double n = static_cast<double>(particules.size());
                Vector3 centre = simToRay(cx/n, cy/n, cz/n);
                Vector3 offset = { camera.position.x - camera.target.x,
                                   camera.position.y - camera.target.y,
                                   camera.position.z - camera.target.z };
                camera.target   = centre;
                camera.position = { centre.x + offset.x,
                                    centre.y + offset.y,
                                    centre.z + offset.z };
            }
        }

        UpdateCamera(&camera, cameraMode);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                DrawGrid(20, 1.0f);
                systeme.dessine_sur(*this);
            EndMode3D();
            DrawFPS(10, 10);
            DrawText("Note: epsilon=25 too small to bounce off Plan", 10, 30, 14, GRAY);
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
    // Try to draw Plan as a flat surface
    Plan const* plan = dynamic_cast<Plan const*>(&o);
    if (plan != nullptr) {
        Vecteur3D pos = plan->getPos();
        Vector3 rPos  = simToRay(pos.getX(), pos.getY(), pos.getZ());
        // Draw a large flat plane; raylib DrawPlane uses Y-up normal
        DrawPlane(rPos, { 20.0f, 20.0f }, LIGHTGRAY);
    }
}

void raylibRender::dessine(Source const& s)
{
    Vecteur3D pos = s.getPosition();
    Vector3 rPos  = simToRay(pos.getX(), pos.getY(), pos.getZ());
    DrawSphere(rPos, 0.2f, YELLOW);
}
