#pragma once

#include "support_a_dessin.h"
#include "contenu.h"
#include <raylib.h>
#include "rcamera.h"
#include <vector>

class raylibRender : public SupportADessin {
public:
    raylibRender();
    ~raylibRender() override;

    void run();

    void dessine(Contenu const& a_dessiner) override;

    int cameraMode;
private:
    Camera3D camera;

    std::vector<Contenu> liste_contenus;
};
