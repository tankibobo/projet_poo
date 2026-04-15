#pragma once

#include "../general/SupportADessin/SupportADessin.h"
#include "../general/Particule/Particule.h"
#include "../general/Systeme/Systeme.h"
#include "../general/Obstacle/Obstacle.h"
#include "../general/Source/Source.h"
#include <raylib.h>
#include "rcamera.h"

class raylibRender : public SupportADessin {
public:
    raylibRender();
    ~raylibRender() override;

    void run(Systeme& systeme);

    void dessine(Particule const& p) override;
    void dessine(Systeme const& s)   override;
    void dessine(Obstacle const& o)  override;
    void dessine(Source const& s)    override;

    int cameraMode;

private:
    Camera3D camera;
};
