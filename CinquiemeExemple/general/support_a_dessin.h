#pragma once

class Contenu;

class SupportADessin {
public:

    virtual void dessine(Contenu const& a_dessiner) = 0;

    // destructeur virtuel (classe abstraite)
    virtual ~SupportADessin() = default;

    // Il ne faut pas pouvoir copier les supports à dessin car liés à raylibRender qui perd la mémoire de l'adresse du support à dessin à chaque copie.
    SupportADessin(SupportADessin const&)            = delete;
    SupportADessin& operator=(SupportADessin const&) = delete;
    SupportADessin(SupportADessin&&)            = default;
    SupportADessin& operator=(SupportADessin&&) = default;

    SupportADessin() = default;
};