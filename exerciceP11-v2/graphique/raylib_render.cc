#include "raylib_render.h"
#include "Plan/Plan.h"
#include "ParticuleNeige/ParticuleNeige.h"
#include "ParticuleRoche/ParticuleRoche.h"
#include <raylib.h>
#include <string>


// sim(x, y, z) → ray(x, z_sim, y_sim)
static Vector3 simToRay(double x, double y, double z) {
    return { static_cast<float>(x), static_cast<float>(z), static_cast<float>(y) };
}


raylibRender::raylibRender() : deplacement(false) {
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(900, 650, "Simulation P11-v2 : Neige & Roche");


    camera.position = { 0.0f, 8.0f, -6.0f };
    camera.target = { 0.0f, 2.0f, 4.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 50.0f;
    camera.projection = CAMERA_PERSPECTIVE;


    SetTargetFPS(60);
}


raylibRender::~raylibRender() {
    CloseWindow();
}


void raylibRender::run(Systeme& systeme) {
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_L)) deplacement = !deplacement;
        if (deplacement) UpdateCamera(&camera, CAMERA_FREE);


        systeme.evolue();


        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                DrawGrid(24, 1.0f);
                systeme.dessine_sur(*this);
            EndMode3D();


            DrawRectangle(8, 8, 320, 80, Fade(LIGHTGRAY, 0.7f));
            DrawText("Appuyez sur 'L' : camera libre (WASD + souris)", 14, 14, 14, DARKGRAY);
            DrawText((std::string("Camera : ") + (deplacement ? "libre" : "fixe")).c_str(), 14, 32, 14, DARKGRAY);
            DrawRectangle(14, 50, 14, 14, SKYBLUE);
            DrawText("ParticuleNeige (e=25, s=0.885)", 34, 50, 14, DARKBLUE);
            DrawRectangle(14, 68, 14, 14, BROWN);
            DrawText("ParticuleRoche (e=45, s=0.600)", 34, 68, 14, MAROON);
            DrawFPS(10, 96);
        EndDrawing();
    }
}


void raylibRender::dessine(Particule const& p) {
    Vector3 rPos = simToRay(p.get_position().getX(), p.get_position().getY(), p.get_position().getZ());
    float r = static_cast<float>(p.getRayon());


    Color couleur = GRAY, couleurFil = DARKGRAY;
    if (dynamic_cast<ParticuleNeige const*>(&p)) {
        couleur = SKYBLUE; couleurFil = DARKBLUE;
    } else if (dynamic_cast<ParticuleRoche const*>(&p)) {
        couleur = BROWN; couleurFil = MAROON;
    }


    DrawSphere(rPos, r, couleur);
    DrawSphereWires(rPos, r, 8, 8, couleurFil);
}


void raylibRender::dessine(Systeme const& s) {
    for (auto* p : s.getParticules()) p->dessine_sur(*this);
    for (auto* o : s.getObstacles()) o->dessine_sur(*this);
    for (auto* src : s.getSources()) src->dessine_sur(*this);
}


void raylibRender::dessine(Obstacle const& o) {
    Brique const* boite = dynamic_cast<Brique const*>(&o);
    if (boite) {
        Vecteur3D c = boite->getCentre();
        Vector3 rCentre = simToRay(c.getX(), c.getY(), c.getZ());


        // Dimensions dans le repère ray : sim(x,y,z) → ray(x,z,y)
        auto absf = [](float v) { return v < 0.0f ? -v : v; };
        Vecteur3D dir_longueur = boite->getDirLongueur();
        Vecteur3D dir_largeur = boite->getDirLargeur();
        Vecteur3D dir_profondeur = boite->getDirProfondeur();
        float longueur = static_cast<float>(boite->getLongueur());
        float largeur = static_cast<float>(boite->getLargeur());
        float profondeur = static_cast<float>(boite->getProfondeur());


        float ray_x = longueur*absf(static_cast<float>(dir_longueur.getX()))
                    + largeur *absf(static_cast<float>(dir_largeur.getX()))
                    + profondeur*absf(static_cast<float>(dir_profondeur.getX()));
        float ray_y = longueur*absf(static_cast<float>(dir_longueur.getZ()))
                    + largeur *absf(static_cast<float>(dir_largeur.getZ()))
                    + profondeur*absf(static_cast<float>(dir_profondeur.getZ()));
        float ray_z = longueur*absf(static_cast<float>(dir_longueur.getY()))
                    + largeur *absf(static_cast<float>(dir_largeur.getY()))
                    + profondeur*absf(static_cast<float>(dir_profondeur.getY()));


        DrawCube(rCentre, ray_x, ray_y, ray_z, Fade(DARKGRAY, 0.55f));
        DrawCubeWires(rCentre, ray_x, ray_y, ray_z, GRAY);
        return;
    }


    Plan const* plan = dynamic_cast<Plan const*>(&o);
    if (plan) {
        Vector3 rPos = simToRay(plan->getPos().getX(), plan->getPos().getY(), plan->getPos().getZ());
        if (plan->getNormale().getZ() > 0.9)
            DrawPlane(rPos, {24.0f, 24.0f}, Fade(LIGHTGRAY, 0.6f));
        else {
            DrawCube(rPos, 24.0f, 12.0f, 0.15f, Fade(BEIGE, 0.4f));
            DrawCubeWires(rPos, 24.0f, 12.0f, 0.15f, DARKGRAY);
        }
    }
}


void raylibRender::dessine(Source const& s) {
    Vector3 rPos = simToRay(s.getPosition().getX(), s.getPosition().getY(), s.getPosition().getZ());


    Color couleur = YELLOW;
    if (dynamic_cast<ParticuleNeige const*>(&s.getParticule())) couleur = SKYBLUE;
    else if (dynamic_cast<ParticuleRoche const*>(&s.getParticule())) couleur = BROWN;


    DrawSphere(rPos, 0.25f, couleur);
    DrawSphereWires(rPos, 0.25f, 8, 8, DARKGRAY);
}
