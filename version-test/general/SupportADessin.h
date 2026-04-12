class Particule;
class Obstacle;
class Systeme;
class Source;
#pragma once

class SupportADessin {
    public:
    // on suppose ici que les supports ne seront ni copiés ni déplacés

    virtual void dessine(Particule const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Obstacle const&) = 0;
    virtual void dessine(Source const&) = 0;
    // ... autres choses que vous voudriez « dessiner »...

    virtual ~SupportADessin() = default;

    // on ne copie pas les supports à dessin
    SupportADessin(SupportADessin const&)            = delete;
    SupportADessin& operator=(SupportADessin const&) = delete;

    // mais on peut les déplacer
    SupportADessin(SupportADessin&&)            = default;
    SupportADessin& operator=(SupportADessin&&) = default;

    // on remet aussi la version par défaut du constructeur par défaut
    SupportADessin() = default;
};