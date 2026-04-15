#include "raylib_render.h"

raylibRender::raylibRender()
: liste_contenus({
      Contenu(),
      Contenu({-1,1,1}, VERT),
      Contenu({-1,0,1}, ROUGE)
  })
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
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                // Afin de bien voir le cube, on va dessiner une grille.
                DrawGrid(200, 0.5f);

                // Et on dessine le contenu.
                for (auto const& contenu : liste_contenus) {
                    contenu.dessine_sur(*this);
                }
            EndMode3D();
        EndDrawing();
    }
}

void raylibRender::dessine(Contenu const& a_dessiner)
{
    const auto [x, y, z] = a_dessiner.get_position();
    const Vector3 position = { static_cast<float>(x), static_cast<float>(y), static_cast<float>(z) };
    auto color = WHITE;
    switch (a_dessiner.get_color()) {
        case ROUGE:
            color = RED;
            break;
        case VERT:
            color = GREEN;
            break;
        case BLEU:
            color = BLUE;
            break;
        default:
            color = WHITE;
            break;
    }
    DrawCube(position, 1.0f, 1.0f, 1.0f, color);
    DrawCubeWires(position, 1.0f, 1.0f, 1.0f, BLACK);
}
