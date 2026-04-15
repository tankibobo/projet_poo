#include "raylib_render.h"

raylibRender::raylibRender()
{
    // parmétres de la fenêtre
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Un cube");

    // paramétres de la caméra
    camera.position = { 5.0f, 5.0f, 5.0f };
    camera.target   = { 0.0f, 1.0f, 0.0f };
    camera.up = camera.target;
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);
}

raylibRender::~raylibRender()
{
    CloseWindow();
}

void raylibRender::run()
{
    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                // Afin de bien voir le cube, on va dessiner une grille.
                DrawGrid(200, 0.5f);

                // Et on dessine le contenu.
                c.dessine_sur(*this);
            EndMode3D();
        EndDrawing();
    }
}

void raylibRender::dessine(Contenu const& a_dessiner)
{
    constexpr Vector3 position({ 0.0f, 1.0f, 0.0f });
    DrawCube(position, 2.0f, 2.0f, 2.0f, LIME);
    DrawCubeWires(position, 2.0f, 2.0f, 2.0f, DARKGREEN);
}