#pragma once

#include "dessinable.h"
#include "support_a_dessin.h"

enum Couleur {
    NONE,
    ROUGE,
    VERT,
    BLEU
};

struct Position {
    double x;
    double y;
    double z;
};

class Contenu : public Dessinable {
public:
    // à adapter suivant les besoins :
    ~Contenu()                override = default;
    Contenu(Contenu const&)            = default;
    Contenu& operator=(Contenu const&) = default;
    Contenu(Contenu&&)                 = default;
    Contenu& operator=(Contenu&&)      = default;
    Contenu(const Position &p = {0, 0, 0}, const Couleur c = NONE)
    : position(p), color(c) {}

    Position get_position() const { return position; }
    Couleur get_color() const { return color; }

    /*
     * Ceci est la méthode devant être ajoutée à toute classe
     * étendant Dessinable, afin de pouvoir être dessinée correctement.
     */
    void dessine_sur(SupportADessin& support) const override
    { support.dessine(*this); }

    /*
     * Le reste de la classe peut être quelconque selon les besoins.
     */

     private:
        Position position;
        Couleur color;
};
