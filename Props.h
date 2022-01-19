#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
#include "ITheatricalThings.h"
using namespace std;

class Props : public ITheatricalThings
{
public:
    int hazardLevel;
    int serviceLife;
    int periodOfUse;
    int price;
    bool status;


    Props(int newHazardLevel, int newServiceLife, int newPrice) {
        hazardLevel = newHazardLevel;
        serviceLife = newServiceLife;
        price = newPrice;
    }

    void securityCheck()
    {
        if (periodOfUse >= serviceLife && hazardLevel > 2)
        {
            status = false;
        }
    }

    void printProps()
    {
        cout << "������� ���������: " << hazardLevel << endl;
        cout << "���� ������: " << serviceLife << endl;
        cout << "������ �������������: " << periodOfUse << endl;
        cout << "����: " << price << endl;
        if (status)
        {
            cout << "������: ������������\n" << endl;
        }
        else
        {
            cout << "������: �������\n" << endl;
        }
    }

    int getPrice()
    {
        return price;
    }

};

