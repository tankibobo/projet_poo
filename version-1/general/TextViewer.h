#include "SupportADessin.h"
#include <iostream>
#include "Particule.h"
#include "Systeme.h"
#include "Obstacle.h"
#pragma once;

class TextViewer : public SupportADessin {
    public:
        virtual void dessine(Particule const& p) {os << p;};
        virtual void dessine(Systeme const& s) {os << s;};
        virtual void dessine(Obstacle const& o) {os << o;};

        //cons et destr et copie
        explicit TextViewer(std::ostream& os_) : os(os_) {} //explicit poir les constructeur à un argument (conversions "implicites")
        TextViewer(TextViewer const&) = delete;
        TextViewer& operator=(TextViewer const&) = delete;
        TextViewer(TextViewer&&) = default;
        TextViewer& operator=(TextViewer&&)      = default;
        ~TextViewer() = default;
    private:
        std::ostream& os;
};