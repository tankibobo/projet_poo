#pragma once

class SupportADessin; // pré-déclaration

class Dessinable {
public:

    // la raison d'être des Dessinable
    virtual void dessine_sur(SupportADessin&) const = 0;

    // destructeur virtuel (puisque classe abstraite)
    virtual ~Dessinable()                    = default;

    // remise par défaut des constructeurs de copie et de déplacement
    Dessinable(Dessinable const&)            = default;
    Dessinable& operator=(Dessinable const&) = default;
    Dessinable(Dessinable&&)                 = default;
    Dessinable& operator=(Dessinable&&)      = default;

    // et remise aussi par défaut du constructeur par défaut
    Dessinable() = default;
};