#pragma once
#include <iostream>
#include "../general/SupportADessin/SupportADessin.h"
#include "../general/Particule/Particule.h"
#include "../general/Systeme/Systeme.h"
#include "../general/Obstacle/Obstacle.h"
#include "../general/Source/Source.h"

class TextViewer : public SupportADessin {
public:
    virtual void dessine(Particule const& p) override { os << p; }
    virtual void dessine(Systeme const& s)   override { os << s; }
    virtual void dessine(Obstacle const& o)  override { os << o; }
    virtual void dessine(Source const& s)    override { os << s; }

    explicit TextViewer(std::ostream& os_) : os(os_) {}
    TextViewer(TextViewer const&)            = delete;
    TextViewer& operator=(TextViewer const&) = delete;
    TextViewer(TextViewer&&)                 = delete;
    TextViewer& operator=(TextViewer&&)      = delete;
    ~TextViewer() = default;

private:
    std::ostream& os;
};
