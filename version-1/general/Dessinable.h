#pragma once
#include "SupportADessin.h"
// sous classes de dessinable: particule, obstacle, source,

class Dessinable {
    public:
        virtual void dessine_sur(SupportADessin&) = 0;
        // mise en virtuel du destructeur (puisque classe abstraite)
        virtual ~Dessinable()                    = default;

        // remise par défaut des constructeurs de copie et de déplacement
        Dessinable(Dessinable const&)            = default;
        Dessinable& operator=(Dessinable const&) = default;
        Dessinable(Dessinable&&)                 = default;
        Dessinable& operator=(Dessinable&&)      = default;

        // et remise aussi par défaut du constructeur par défaut
        Dessinable() = default;
};