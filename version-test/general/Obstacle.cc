#include "Obstacle.h"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Obstacle& o) {
    return o.affiche(os);
}