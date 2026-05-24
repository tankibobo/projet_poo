// fonctionne et cmake verifié
#include "Plan.h"
#include <iostream>

int main() {
    Plan p1(0, 0, 2);
    Plan p2(0, 1, 0);
    Plan p3(1, 0, 0);
    Plan p4(1, 1, 1);
    Plan p5(1, 2, 3, 1.1, 3.3, 2.2);

    std::vector<Plan> plans = {p1, p2, p3, p4, p5};

    Vecteur3D t1(0, 7, 0);
    Vecteur3D t2(0, 0, 10);
    Vecteur3D t3(2, 0, 0);
    Vecteur3D t4(5, -4, 6);

    std::vector<Vecteur3D> tests = {t1, t2, t3, t4};

    for (const auto& plan : plans) {
    std::cout << "Plan d'origine (" << plan.getX() << " " << plan.getY() << " " << plan.getZ() << ") et de normale (" << plan.getNormale() << ") : " << std::endl;
    for (const auto& test : tests) {
        std::cout << "distance à (" << test << ") : (" << plan.PointPlusProche(test) << ")" << std::endl;
    }
}

    return 0;
}

