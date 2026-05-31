#pragma once

// prédéclaration de tous les contenus que l'on veut dessiner
class Contenu;
// ....

class SupportADessin {
public:

    /*
     * La raison d'être des Dessinable
     */
    virtual void dessine(Contenu const& a_dessiner) = 0;

    // mise en virtuel du destructeur (puisque classe abstraite)
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