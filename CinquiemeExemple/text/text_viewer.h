#pragma once

#include <iostream>
#include "support_a_dessin.h"

class TextViewer : public SupportADessin {
public:
    explicit TextViewer(std::ostream& flot_) : flot(flot_) {}

    ~TextViewer() override                   = default;
    TextViewer(TextViewer const&)            = delete;
    TextViewer& operator=(TextViewer const&) = delete;
    TextViewer(TextViewer&&)                 = default;
    TextViewer& operator=(TextViewer&&)      = default;

    void dessine(Contenu const& a_dessiner) override;

private:
    std::ostream& flot;
};