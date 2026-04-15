#pragma once

#include "support_a_dessin.h"
#include "contenu.h"
#include <raylib.h>

class raylibRender : public SupportADessin {
public:
    raylibRender();
    ~raylibRender() override;

    void run();

    void dessine(Contenu const& a_dessiner) override;

    
private:
    Camera3D camera;

    Contenu c;
};
