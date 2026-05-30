#pragma once
#include "../SupportADessin/SupportADessin.h"


class Dessinable {
    public:
        virtual void dessine_sur(SupportADessin&) = 0;
        virtual ~Dessinable() = default;

        // viens du tutoriel graphique 
        Dessinable(Dessinable const&) = default;
        Dessinable& operator=(Dessinable const&) = default;
        Dessinable(Dessinable&&) = default;
        Dessinable& operator=(Dessinable&&) = default;


        Dessinable() = default; // sinon on ne peut pas initialiser les sous classes par défaut
};
