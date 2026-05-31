#include "raylib_render.h"
#include "Plan/Plan.h"
#include "Cylindre/Cylindre.h"
#include "ParticuleNeige/ParticuleNeige.h"
#include "ParticuleRoche/ParticuleRoche.h"
#include <raylib.h>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>


// sim(x, y, z) → ray(x, z_sim, y_sim)
static Vector3 simToRay(double x, double y, double z) {
    return { static_cast<float>(x), static_cast<float>(z), static_cast<float>(y) };
}


// Formate un double en notation scientifique avec 3 chiffres après la virgule
// utilisé que ici donc static
static std::string fmtSci(double v) {
    std::ostringstream oss;
    oss << std::scientific << std::setprecision(3) << v;
    return oss.str();
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

        // Contrôles des sources
        const std::vector<Source*>& srcs = systeme.getSources();
        if (IsKeyPressed(KEY_O)) {
            for (Source* s : srcs) s->toggleEtat();
        }
        if (IsKeyPressed(KEY_UP)) {
            for (Source* s : srcs) s->setDebit(s->getDebit() + 10.0);
        }
        if (IsKeyPressed(KEY_DOWN)) {
            for (Source* s : srcs) s->setDebit(s->getDebit() - 10.0);
        }


        systeme.evolue();


        // ── Calcul des énergies ──
        const std::vector<Particule*>& parts = systeme.getParticules();

        // Énergie cinétique : Ec = 1/2 m v^2
        double Ec = 0.0;
        for (auto* p : parts) {
            double v2 = p->get_vitesse() | p->get_vitesse();
            Ec += 0.5 * p->getMasse() * v2;
        }

        // Énergie potentielle de Lennard-Jones : Ep = 4ε[(σ/r)^12 - (σ/r)^6]
        double Ep = 0.0;
        for (size_t i = 0; i < parts.size(); ++i) {
            for (size_t j = i+1; j < parts.size(); ++j) {
                double r = (parts[j]->get_position() - parts[i]->get_position()).norme();
                double sig = 0.5 * (parts[i]->getSigma() + parts[j]->getSigma());
                double eps = std::sqrt(parts[i]->getEpsilon() * parts[j]->getEpsilon());
                if ((r > 0.0) and (r < 2.0*sig)) {
                    double sr6 = std::pow(sig/r, 6);
                    Ep += 4.0 * eps * (sr6*sr6 - sr6);
                }
            }
        }

        double Em = Ec + Ep;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                DrawGrid(24, 1.0f);
                systeme.dessine_sur(*this);
            EndMode3D();


            // HUD contrôles
            DrawRectangle(8, 8, 340, 116, Fade(LIGHTGRAY, 0.7f));
            DrawText("'L' : camera libre (WASD + souris)", 14, 14, 14, DARKGRAY);
            DrawText((std::string("Camera : ") + (deplacement ? "libre" : "fixe")).c_str(), 14, 30, 14, DARKGRAY);
            DrawText("'O' : sources on/off", 14, 46, 14, DARKGRAY);
            DrawText("'UP'/'DOWN' : debit +/-10", 14, 62, 14, DARKGRAY);
            
            if (!srcs.empty()) {
                bool actives = srcs[0]->getEtat();
                std::string etatStr = std::string("Sources : ") + (actives ? "ON" : "OFF")
                                    + "  debit=" + std::to_string(static_cast<int>(srcs[0]->getDebit()));
                DrawText(etatStr.c_str(), 14, 78, 14, actives ? DARKGREEN : RED);
            }
            DrawRectangle(14, 96, 14, 14, SKYBLUE);
            DrawText("ParticuleNeige (e=25, s=0.885)", 34, 96, 14, DARKBLUE);
            DrawRectangle(14, 112, 14, 14, BROWN);
            DrawText("ParticuleRoche (e=45, s=0.600)", 34, 112, 14, MAROON);
            DrawFPS(10, 130);

            // HUD énergies
            DrawRectangle(8, 230, 240, 60, Fade(LIGHTGRAY, 0.7f));
            DrawText(("Ec = " + fmtSci(Ec) + " J").c_str(), 14, 236, 14, DARKGREEN);
            DrawText(("Ep = " + fmtSci(Ep) + " J").c_str(), 14, 254, 14, ORANGE);
            DrawText(("Em = " + fmtSci(Em) + " J").c_str(), 14, 272, 14, MAROON);
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
    //dynamic_cast pour vérifier que l'obstacle est bien une Brique, nous permet de pas avoir à faire une fonction de dessin pour chaque type d'obstacle
    Brique const* b = dynamic_cast<Brique const*>(&o);
    if (b) {
        // Dimensions dans le repère ray : sim(x,y,z) → ray(x,z,y)
        Vecteur3D c = b->getCentre();
        Vector3 rCentre = simToRay(c.getX(), c.getY(), c.getZ());
        Vecteur3D dir_longueur = b->getDirLongueur();
        Vecteur3D dir_largeur = b->getDirLargeur();
        Vecteur3D dir_profondeur = b->getDirProfondeur();
        //static_cast<> pour éviter les warnings de conversion double → float
        float longueur = static_cast<float>(b->getLongueur());
        float largeur = static_cast<float>(b->getLargeur());
        float profondeur = static_cast<float>(b->getProfondeur());
        float ray_x = longueur*std::abs(static_cast<float>(dir_longueur.getX())) + largeur*std::abs(static_cast<float>(dir_largeur.getX())) + profondeur*std::abs(static_cast<float>(dir_profondeur.getX()));
        float ray_y = longueur*std::abs(static_cast<float>(dir_longueur.getZ())) + largeur*std::abs(static_cast<float>(dir_largeur.getZ())) + profondeur*std::abs(static_cast<float>(dir_profondeur.getZ()));
        float ray_z = longueur*std::abs(static_cast<float>(dir_longueur.getY())) + largeur*std::abs(static_cast<float>(dir_largeur.getY())) + profondeur*std::abs(static_cast<float>(dir_profondeur.getY()));
        DrawCube(rCentre, ray_x, ray_y, ray_z, Fade(DARKGRAY, 0.55f));
        DrawCubeWires(rCentre, ray_x, ray_y, ray_z, GRAY);
        return;
    }
    Cylindre const* cyl = dynamic_cast<Cylindre const*>(&o);
    if (cyl) {
        Vecteur3D c = cyl->getCentre();
        Vecteur3D n = cyl->getNormale();
        double h = cyl->getHauteur() / 2.0;
        Vecteur3D startSim = c - h * n;
        Vecteur3D endSim   = c + h * n;
        Vector3 rStart = simToRay(startSim.getX(), startSim.getY(), startSim.getZ());
        Vector3 rEnd   = simToRay(endSim.getX(),   endSim.getY(),   endSim.getZ());
        float r = static_cast<float>(cyl->getRayon());
        DrawCylinderEx(rStart, rEnd, r, r, 12, Fade(DARKBROWN, 0.8f));
        DrawCylinderWiresEx(rStart, rEnd, r, r, 12, BROWN);
        return;
    }
    Plan const* plan = dynamic_cast<Plan const*>(&o);
    if (plan) {
        Vector3 rPos = simToRay(plan->getPos().getX(), plan->getPos().getY(), plan->getPos().getZ());
        if ((plan->getNormale().getZ() > 0.9))
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


    DrawCube(rPos, 0.5f, 0.5f, 0.5f, RED);
    DrawCubeWires(rPos, 0.5f, 0.5f, 0.5f, DARKGRAY);
}
