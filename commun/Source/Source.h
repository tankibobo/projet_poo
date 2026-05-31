// constructeurs demandent un generateur, peut être on peut éviter avec un troisieme constructeur a voir pas sûr
// a voir si on rajoute des setters pour les attributs, je pense il y a peu d'intérêts


#pragma once
#include <vector>
#include "../Aleatoire/Aleatoire.h"
#include "../Vecteur3D/Vecteur3D.h"
#include "../Dessinable/Dessinable.h"
#include "../SupportADessin/SupportADessin.h"
#include <ostream>


class Particule;


class Source : public Dessinable {
    public:
        Source(Particule const& modele_, double x, double y, double z, Aleatoire& generateur_) : position(x,y,z), vitesse_moyenne(0,0,1), ecart_type_vitesse(1), ecart_type_rayon(1), debit(1), etat(true), modele(modele_), generateur(generateur_) {};
        Source(Particule const& modele_, double x, double y, double z, double ecart_v, double ecart_r, double debit_, bool etat_, Aleatoire& generateur_) : position(x,y,z), vitesse_moyenne(0,0,1), ecart_type_vitesse(ecart_v), ecart_type_rayon(ecart_r), debit(debit_), etat(etat_), modele(modele_), generateur(generateur_) {};


        void on()  {etat = true;}
        void off() {etat = false;}
        void toggleEtat() {etat = !etat;}
        void setDebit(double d) {if (d >= 0.0) debit = d;}


        Vecteur3D getPosition() const {return position;}
        bool getEtat() const {return etat;}
        double getDebit() const {return debit;}
        Vecteur3D getVitesseMoyenne() const {return vitesse_moyenne;}
        double getEcartTypeVitesse() const {return ecart_type_vitesse;}
        double getEcartTypeRayon() const {return ecart_type_rayon;}
        Particule const& getParticule() const {return modele;}
        Source(Source const&) = delete;
        Source& operator=(Source const&) = delete;


        void creation(std::vector<Particule*>& particules, double dt);
        virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }


    private:
        Vecteur3D position;
        Vecteur3D vitesse_moyenne;
        double ecart_type_vitesse;
        double ecart_type_rayon;
        double debit;
        bool etat;
        Particule const& modele;
        Aleatoire& generateur;


};


std::ostream& operator<<(std::ostream& os, const Source& s);
