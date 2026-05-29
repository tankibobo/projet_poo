#pragma once
#include "SupportADessin/SupportADessin.h"
#include "Particule/Particule.h"
#include "Systeme/Systeme.h"
#include "Obstacle/Obstacle.h"
#include "Source/Source.h"
#include "Brique/Brique.h"
#include <raylib.h>


class raylibRender : public SupportADessin {
public:
    raylibRender();
    ~raylibRender() override;


    void run(Systeme& systeme);


    void dessine(Particule const& p) override;
    void dessine(Systeme const& s) override;
    void dessine(Obstacle const& o) override;
    void dessine(Source const& s) override;


private:
    Camera3D camera;
    bool deplacement;
};
