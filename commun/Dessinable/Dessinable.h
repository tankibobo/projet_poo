#pragma once
#include "../SupportADessin/SupportADessin.h"


class Dessinable {
    public:
        virtual void dessine_sur(SupportADessin&) = 0;
        virtual ~Dessinable() = default;


        // constructeurs de copie et de déplacement par défaut
        Dessinable(Dessinable const&) = default;
        Dessinable& operator=(Dessinable const&) = default;
        Dessinable(Dessinable&&) = default;
        Dessinable& operator=(Dessinable&&) = default;


        // et remise aussi par défaut du constructeur par défaut
        Dessinable() = default;
};
