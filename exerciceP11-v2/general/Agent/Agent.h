#pragma once
class ParticuleRoche;
class ParticuleNeige;


class Agent {
    public:
        virtual void opere_sur(ParticuleNeige& p) = 0;
        virtual void opere_sur(ParticuleRoche& p) = 0;
        virtual ~Agent() {}
};
