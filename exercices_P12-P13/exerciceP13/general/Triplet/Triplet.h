#pragma once

class Triplet {
    public:
        Triplet(int x, int y, int z) : x(x), y(y), z(z) {}
        bool operator<(const Triplet& autre) const {
            if (x != autre.x) return x < autre.x;
            if (y != autre.y) return y < autre.y;
            return z < autre.z;
        }
        int x;
        int y;
        int z;
};