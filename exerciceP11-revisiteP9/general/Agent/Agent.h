#pragma once
class ParticuleNeige;


class Agent {
    public:
        virtual void opere_sur(ParticuleNeige& p) = 0;
        virtual ~Agent() {}
};
