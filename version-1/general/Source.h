// constructeurs demandent un generateur, peut être on peut éviter avec un troisieme constructeur a voir pas sûr
// a voir si on rajoute des setters pour les attributs, j'ai pas trop compris le truc Aleatoire

#pragma once
#include "Aleatoire.h"
#include "Particule.h"
#include "Vecteur3D.h"

class Source {
    public:
        Source(Particule const& modele, double x, double y, double z, Aleatoire& generateur) : position(x,y,z), vitesse_moyenne(0,0,1), ecart_type_vitesse(1), ecart_type_rayon(1), debit(1), etat(true), modele(modele), generateur(generateur) {};
        Source(Particule const& modele, double x, double y, double z, double ecart_v, double ecart_r, double debit, bool etat, Aleatoire& generateur) : position(x,y,z), vitesse_moyenne(0,0,1), ecart_type_vitesse(ecart_v), ecart_type_rayon(ecart_r), debit(debit), etat(etat), modele(modele), generateur(generateur) {};

        void on() {etat = true;}
        void off() {etat = false;}

        Vecteur3D getPosition() const {return position;}
        bool getEtat() const {return etat;}
        double getDebit() const {return debit;}
        Vecteur3D getVitesseMoyenne() const {return vitesse_moyenne;}
        double getEcartTypeVitesse() const {return ecart_type_vitesse;}
        double getEcartTypeRayon() const {return ecart_type_rayon;}
        Particule const& getParticule() const {return modele;}

        // vrmt pas sûr que la fonction sort Particuel& mais on verra :)
        void creation(std::vector<Particule*>& particules, double dt);
        

    private:
        Particule const& modele;
        Vecteur3D position;
        Vecteur3D vitesse_moyenne;
        double ecart_type_vitesse;
        double ecart_type_rayon;
        double debit;
        bool etat;
        Aleatoire& generateur;

};