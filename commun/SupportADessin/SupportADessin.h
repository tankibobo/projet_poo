#pragma once
class Particule;
class Obstacle;
class Systeme;
class Source;


class SupportADessin {
    public:
    // on suppose ici que les supports ne seront ni copiés ni déplacés


    virtual void dessine(Particule const&) = 0;
    virtual void dessine(Obstacle const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Source const&) = 0;


    virtual ~SupportADessin() = default;


    // on ne copie pas les supports à dessin car raylibRender perd ses données spécifiques
    SupportADessin(SupportADessin const&) = delete;
    SupportADessin& operator=(SupportADessin const&) = delete;

    SupportADessin(SupportADessin&&) = default;
    SupportADessin& operator=(SupportADessin&&) = default;


    // on remet aussi la version par défaut du constructeur par défaut
    SupportADessin() = default;
};
