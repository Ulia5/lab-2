#pragma once
#include "Props.h"
class Sword :
    public Props
{
public:
    Sword(int newHazardLevel, int newServiceLife, int newPrice) : Props(newHazardLevel, newServiceLife, newPrice) {
        periodOfUse = 0;
        status = true;
    }

    void changePeriodOfUse(int period)
    {
        periodOfUse += period;
        securityCheck();
    }

};

