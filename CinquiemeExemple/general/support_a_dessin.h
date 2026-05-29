#pragma once

class Contenu;

class SupportADessin {
public:

    virtual void dessine(Contenu const& a_dessiner) = 0;

    // mise en virtuel du destructeur (puisque classe abstraite)
    virtual ~SupportADessin() = default;

    // on ne copie pas les supports à dessin
    SupportADessin(SupportADessin const&)            = delete;
    SupportADessin& operator=(SupportADessin const&) = delete;
    SupportADessin(SupportADessin&&)            = default;
    SupportADessin& operator=(SupportADessin&&) = default;

    SupportADessin() = default;
};