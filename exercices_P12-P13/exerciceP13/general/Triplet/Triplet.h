#pragma once

class Triplet {
    public:
        Triplet(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {}
        bool operator<(const Triplet& autre) const {
            if (x != autre.x) return x < autre.x;
            if (y != autre.y) return y < autre.y;
            return z < autre.z;
        }
        int x;
        int y;
        int z;
};