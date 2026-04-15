#pragma once

#include "dessinable.h"
#include "support_a_dessin.h"

class Contenu : public Dessinable {
public:
    // à adapter suivant les besoins :
    ~Contenu()                override = default;
    Contenu(Contenu const&)            = default;
    Contenu& operator=(Contenu const&) = default;
    Contenu(Contenu&&)                 = default;
    Contenu& operator=(Contenu&&)      = default;
    Contenu()                          = default;

    /*
     * Ceci est la méthode devant être ajoutée à toute classe
     * étendant Dessinable, afin de pouvoir être dessinée correctement.
     */
    void dessine_sur(SupportADessin& support) const override
    { support.dessine(*this); }

    /*
     * Le reste de la classe peut être quelconque selon les besoins.
     */
};
